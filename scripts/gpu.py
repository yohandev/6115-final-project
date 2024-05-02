# Simulates the RP2040 GPU. Talks to the PSoC over Serial
from trimesh import Scene, Trimesh, load_mesh
from trimesh.primitives import Sphere, Capsule
from scipy.spatial.transform import Rotation as R
from threading import Thread
from serial import Serial
from queue import Queue
from time import sleep
from struct import unpack

import numpy as np
 

# Payload types
PACKET_OVER = b"\x80"
UPLOAD_MESH = b"\x81"
CLEAR_BUFFER = b"\x82"
SWAP_BUFFER = b"\x83"
SET_CAMERA = b"\x84"
DRAW_INSTANCED = b"\x85"
DRAW_INSTANCED_QUAT = b"\x86"


origin = load_mesh("./assets/debug_camera.ply")
scene = Scene([origin])
meshes = dict()
commands = Queue()

# Annoying amount of book-keeping to refresh the scene graph without flickering
todelete = []
meshid = 0


def read_loop():
    # Give UI thread some time to boot up
    sleep(0.5)

    serial = Serial("/dev/tty.usbmodem1103", 921600)

    # Tell PSoC we're ready to receive data
    sleep(0.6)
    serial.write(b"!")
    
    while True:
        header = serial.read()
        # Oops, this was a print message!
        if header.isascii():
            print(chr(ord(header)), end="")
        # Otherwise parse the packet's payload
        elif header == UPLOAD_MESH:
            id, = unpack("<I", serial.read(4))
            num_vertices, = unpack("<I", serial.read(4))
            vertices = unpack(f"<{num_vertices * 3}h", serial.read(num_vertices * 6))
            num_faces, = unpack("<I", serial.read(4))
            indices = unpack(f"<{num_faces * 3}h", serial.read(num_faces * 6))
            num_colors, = unpack("<I", serial.read(4))
            colors = unpack(f"<{num_colors * 2}h", serial.read(num_colors * 4))

            assert serial.read() == PACKET_OVER

            vertices = (1 / 256) * np.array(vertices, dtype=float).reshape((num_vertices, 3))
            faces = np.array(indices).reshape((num_faces, 3))

            meshes[id] = Trimesh(vertices, faces)
        elif header == CLEAR_BUFFER:
            assert serial.read() == PACKET_OVER
        elif header == SWAP_BUFFER:
            assert serial.read() == PACKET_OVER
            commands.put((SWAP_BUFFER,))
        elif header == SET_CAMERA:
            position = unpack("<3f", serial.read(12))
            rotation = unpack("<4f", serial.read(16))

            assert serial.read() == PACKET_OVER

            commands.put((SET_CAMERA, position, rotation))
        elif header == DRAW_INSTANCED:
            id, = unpack("<I", serial.read(4))
            num_instances, = unpack("<I", serial.read(4))
            positions = unpack(f"<{num_instances * 3}f", serial.read(num_instances * 12))
            rotations = unpack(f"<{num_instances * 3}f", serial.read(num_instances * 12))

            assert serial.read() == PACKET_OVER

            positions = np.array(positions).reshape((num_instances, 3))
            rotations = np.array(rotations).reshape((num_instances, 3))

            commands.put((DRAW_INSTANCED, id, positions, rotations))
        elif header == DRAW_INSTANCED_QUAT:
            id, = unpack("<I", serial.read(4))
            num_instances, = unpack("<I", serial.read(4))
            positions = unpack(f"<{num_instances * 3}f", serial.read(num_instances * 12))
            rotations = unpack(f"<{num_instances * 4}f", serial.read(num_instances * 16))

            assert serial.read() == PACKET_OVER

            positions = np.array(positions).reshape((num_instances, 3))
            rotations = np.array(rotations).reshape((num_instances, 4))

            commands.put((DRAW_INSTANCED_QUAT, id, positions, rotations))
        # Reading mid-packet or something else entirely went wrong!
        else:
            raise ValueError(f"Unexpected packet: {header}")


def render_loop(scene: Scene):
    scene.camera.z_far = 10000.0
    deleted = False

    global todelete, meshid
    while not commands.empty():
        header, *args = commands.get()

        if header == SWAP_BUFFER and not deleted:
            if commands.empty():
                commands.put((SWAP_BUFFER,))
                break
            for node in todelete:
                scene.delete_geometry(node)
                scene.graph.transforms.remove_node(node)
            todelete = []
            deleted = True
            meshid = 0
        elif header == DRAW_INSTANCED:
            id, positions, rotations = args

            for (position, rotation) in zip(positions, rotations):
                pose = np.eye(4, 4)
                pose[:3, :3] = R.from_euler("xyz", rotation, degrees=False).as_matrix()
                pose[:3, 3] = position

                todelete.append(scene.add_geometry(meshes[id], transform=pose, node_name=str(meshid), geom_name=str(meshid)))
                meshid += 1
        elif header == DRAW_INSTANCED_QUAT:
            id, positions, rotations = args

            for (position, rotation) in zip(positions, rotations):
                pose = np.eye(4, 4)
                pose[:3, :3] = R.from_quat(np.roll(rotation, -1)).as_matrix()
                pose[:3, 3] = position

                todelete.append(scene.add_geometry(meshes[id], transform=pose, node_name=str(meshid), geom_name=str(meshid)))
                meshid += 1
        elif header == SET_CAMERA:
            position, rotation = args

            pose = np.eye(4, 4)
            pose[:3, :3] = (R.from_quat(np.roll(rotation, -1)) * R.from_rotvec(np.array([0, np.pi, 0]))).as_matrix()
            pose[:3, 3] = position

            scene.camera_transform = pose
            

            # scene.graph.update(scene.graph.nodes_geometry[0], matrix=pose)


# Serial Thread
Thread(target=read_loop).start()

# UI Thread
scene.show(callback=render_loop, resolution=(1200, 800))