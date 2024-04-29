# Simulates the RP2040 GPU. Talks to the PSoC over Serial
from pyrender import Viewer, Scene, Mesh, Primitive
from threading import Thread
from serial import Serial
from enum import Enum
from trimesh import load_mesh
from time import sleep
from struct import unpack

class PayloadType(Enum):
    PACKET_OVER = 0x80
    UPLOAD_MESH = 0x81
    CLEAR_BUFFER = 0x82
    SWAP_BUFFER = 0x83
    SET_CAMERA = 0x84
    DRAW_INSTANCED = 0x85

# mesh = Mesh.from_trimesh(load_mesh("./assets/star_destroyer.ply"))
scene = Scene()
viewer = Viewer.__new__(Viewer)

meshes = {}     # Meshes submitted from PSoC
cmdbuf = []     # Commands submitted from PSoC that are yet to be flushed
flush = False   # Whether or not the command buffer should be processed yet

def main():
    # Give UI thread some time to boot up
    sleep(0.5)
    
    with Serial("/dev/tty.usbmodem1103", 115200) as serial:
        while True:
            header = serial.read()
            # Oops, this was a print message!
            if header.isascii():
                print(header, end=None)
            # Otherwise parse the packet
            else:
                parse_packet(PayloadType(header), serial)
            
            # Process rendering commands
            if not flush:
                continue
            with viewer.render_lock:
                for (cmd, args) in cmdbuf:
                    pass
                cmdbuf = []
                flush = False


def parse_packet(header: PayloadType, serial: Serial):
    # Parsing utilities
    read_usize = lambda: int.from_bytes(serial.read(4), "little")
    read_u16_array = lambda len: [int.from_bytes(b, "little") for b in serial.read(len * 2)[::2]]
    read_vec3 = lambda: unpack("3f", serial.read(12))
    packet_over = lambda: PayloadType(serial.read()) == PayloadType.PACKET_OVER

    # == Upload Mesh ==
    if header == PayloadType.UPLOAD_MESH:
        id = read_usize()
        num_vertices = read_usize()
        vertices = read_u16_array(num_vertices * 3)
        num_faces = read_usize()
        indices = read_u16_array(num_faces * 3)
        num_colors = read_usize()
        colors = read_u16_array(num_colors * 2)

        # Unpack and store mesh
        vertices = [float(v) / (1 << 8) for v in vertices]
        # TODO: colors
        meshes[id] = Primitive(positions=vertices, indices=indices, mode=4)

        assert packet_over()
    # == Clear Buffer ==
    elif header == PayloadType.CLEAR_BUFFER:
        assert packet_over()
    # == Swap Buffer ==
    elif header == PayloadType.SWAP_BUFFER:
        global flush
        flush = True
        assert packet_over()
    # == Set Camera ==
    elif header == PayloadType.SET_CAMERA:
        pos = read_vec3()
        rot = read_vec3()

        cmdbuf.append((PayloadType.SET_CAMERA, (pos, rot)))

        assert packet_over()
    # == Draw Instanced ==
    elif header == PayloadType.DRAW_INSTANCED:
        id = read_usize()
        num_instances = read_usize()
        pos = [read_vec3() for _ in range(num_instances)]
        rot = [read_vec3() for _ in range(num_instances)]

        cmdbuf.append((PayloadType.DRAW_INSTANCED, (pos, rot)))

        assert packet_over()
    else:
        raise ValueError(f"Unexpected header {header}!")

# Logic thread
Thread(target=main).start()
# UI thread
viewer.__init__(scene, use_raymond_lighting=True)