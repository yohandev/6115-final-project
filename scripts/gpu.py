# Simulates the RP2040 GPU. Talks to the PSoC over Serial
from trimesh import Scene, Trimesh
from trimesh.primitives import Sphere
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


origin = Sphere(center=(0, 0, 0))
scene = Scene([origin])
meshes = dict()
commands = Queue()

# Annoying amount of book-keeping to refresh the scene graph without flickering
todelete = []
meshid = 0


def read_loop():
    # Give UI thread some time to boot up
    sleep(0.5)

    serial = Serial("/dev/tty.usbmodem1103", 115200)

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
            rotation = unpack("<3f", serial.read(12))

            assert serial.read() == PACKET_OVER
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
                pose[:3, 3] = position / 10

                todelete.append(scene.add_geometry(meshes[id], transform=pose, node_name=str(meshid), geom_name=str(meshid)))
                meshid += 1


# def parse_packet(header: PayloadType, serial: Serial):
#     # Parsing utilities
#     def pairwise(i):
#         a = iter(i)
#         return zip(a, a)
#     read_usize = lambda: int.from_bytes(serial.read(4), "little")
#     read_u16_array = lambda len: [unpack("h", bytes(b)) for b in pairwise(serial.read(len * 2))]
#     read_vec3 = lambda: unpack("3f", serial.read(12))
#     read_vec4 = lambda: unpack("4f", serial.read(16))
#     packet_over = lambda: PayloadType(ord(serial.read())) == PayloadType.PACKET_OVER
    
#     # == Upload Mesh ==
#     if header == PayloadType.UPLOAD_MESH:
#         id = read_usize()
#         print(f"Uploading Mesh #{id}")
#         num_vertices = read_usize()
#         print(f"# Vertices: {num_vertices}")
#         vertices = read_u16_array(num_vertices * 3)
#         num_faces = read_usize()
#         print(f"# Faces: {num_faces}")
#         indices = read_u16_array(num_faces * 3)
#         num_colors = read_usize()
#         print(f"# Colors: {num_colors}")
#         colors = read_u16_array(num_colors * 2)
#         print("Unpacking...")

#         # Unpack and store mesh
#         vertices = [float(v) / (1 << 8) for (v,) in vertices]
#         # TODO: colors
#         # meshes[id] = scene.add(Mesh([Primitive(positions=vertices, indices=indices, mode=4)]))
#         meshes[id] = (vertices, indices)

#         assert packet_over()
#     # == Clear Buffer ==
#     elif header == PayloadType.CLEAR_BUFFER:
#         assert packet_over()
#     # == Swap Buffer ==
#     elif header == PayloadType.SWAP_BUFFER:
#         global flush
#         flush = True
#         assert packet_over()
#     # == Set Camera ==
#     elif header == PayloadType.SET_CAMERA:
#         pos = read_vec3()
#         rot = read_vec3()

#         cmdbuf.append((PayloadType.SET_CAMERA, (pos, rot)))

#         assert packet_over()
#     # == Draw Instanced ==
#     elif header == PayloadType.DRAW_INSTANCED:
#         id = read_usize()
#         num_instances = read_usize()
#         pos = [read_vec3() for _ in range(num_instances)]
#         rot = [read_vec3() for _ in range(num_instances)]

#         cmdbuf.append((PayloadType.DRAW_INSTANCED, (id, pos, rot)))

#         assert packet_over()
#     # == Draw Instanced (Quaternions) ==
#     elif header == PayloadType.DRAW_INSTANCED_QUAT:
#         id = read_usize()
#         num_instances = read_usize()
#         pos = [read_vec3() for _ in range(num_instances)]
#         rot = [read_vec4() for _ in range(num_instances)]

#         cmdbuf.append((PayloadType.DRAW_INSTANCED_QUAT, (id, pos, rot)))

#         assert packet_over()
#     else:
#         raise ValueError(f"Unexpected header {header}!")

# def flush_commands():
#     global cmdbuf, flush, mesh
    
#     viewer.render_lock.acquire()
#     print("Frame!")
#     # Not efficient at all but this is essentially what happens on the MCU
#     if mesh:
#         scene.remove_node(mesh)
#         mesh = None
#     primitives = []
#     for (cmd, args) in cmdbuf:
#         if cmd == PayloadType.SET_CAMERA:
#             pass # TODO
#         elif cmd == PayloadType.DRAW_INSTANCED:
#             id, pos, rot = args
#             vertices, indices = meshes[id]
            
#             # Create instances' transformation matrices
#             poses = np.empty((len(pos), 4, 4))
#             poses[:, :3, :3] = R.from_euler("xyz", rot, degrees=False).as_matrix()
#             poses[:, :3, 3] = np.array(pos)

#             primitives.append(Primitive(positions=vertices, indices=indices, mode=4, poses=poses))
                
#                 # node = scene.add(meshes[id])
#                 # node.translation = p
#                 # node.rotation = Rotation.from_euler("xyz", r, degrees=False).as_quat()
#         elif cmd == PayloadType.DRAW_INSTANCED_QUAT:
#             id, pos, rot = args
#             for (p, r) in zip(pos, rot):
#                 # node = scene.add(meshes[id])
#                 # node.translation = p
#                 # node.rotation = (r[1], r[2], r[3], r[0])
#                 pass
#                 # print(f"x-wing is at {p}")
#         else:
#             raise ValueError(f"Unexpected command {cmd} in command buffer!")
#     if primitives:
#         mesh = scene.add(Mesh(primitives))
#     cmdbuf = []
#     flush = False
#     viewer.render_lock.release()

# Serial Thread
Thread(target=read_loop).start()

# UI Thread
scene.show(callback=render_loop)