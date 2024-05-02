# Generates C code for a 3D mesh
# They are formatted to maximize the small amount of RAM/storage available on
# microcontrollers, as folows:
# vertices: list([x, y, z]) where each element is an 8.8 fixed point
# indices: list(i) where each element is an unsigned 16-bit integer, triangles only
# colors: list([i, rgb565]) where i is the starting index for this color
#
# It expects standard polygon files (.ply) with vertex colors. Here are the steps
# to do this succesfully on blender:
# 1. Create and texture the mesh
# 2. Convert everything to triangles
# 3. Create a new color attribute in "Object Data Properties"
# 4. Change render engine to Cycles in "Render Properties"
# 5. Bake the texture to "Active Color Attribute"
# 6. Export the model with ASCII and vertex colors "on". Forward axis (-Z) and up axis (+Y).
#
# The format should be good for maximizing the number of vertices with very little space,
# but it breaks down a tad if using lots of colors or vertices don't occupy the full 8.8
# fixed point range.
import re

from collections import defaultdict

def parse_ply(text: str):
    """Parses Stanford polygon files

    Args:
        text (str): Contents of an ASCII .ply file
    """
    assert text.startswith("ply")

    num_vertices = int(re.search(r"element vertex (\d+)", text).group(1))
    num_faces = int(re.search(r"element face (\d+)", text).group(1))

    vertices = []
    faces = []

    text = text[text.find("end_header"):]
    for line in text.splitlines()[1:]:
        if num_vertices:
            num_vertices -= 1
            vertices.append([float(x) for x in line.split()])
        elif num_faces:
            num_faces -= 1
            count, *indices = line.split()
            faces.append([int(i) for i in indices])

            if count != "3" or len(indices) != 3:
                raise ValueError(f"Not a triangle! {line}")
    return vertices, faces

def vertex_color_to_face(vertices, faces):
    """Goes from vertex color to face color. Alpha is ignored and the first vertex of
    a face determines the color for that entire face. Vertices are returned stripped
    of their color data.
    """
    faces2 = defaultdict(list)
    for [i, j, k] in faces:
        _, _, _, r, g, b, _ = vertices[i]

        faces2[(int(r), int(g), int(b))].append((i, j, k))
    vertices2 = [(x, y, z) for (x, y, z, _, _, _, _) in vertices]

    return vertices2, faces2

def compress_vertices(vertices):
    """Compresses vertices (x, y, z) from floats to 8.8 fixed point"""
    def compress(n):
        out = int(n * (1 << 8))
        trunc = max(-(1 << 15), min((1 << 15) - 1, out))

        if trunc != out:
            print("[Warn] Truncated a vertex.")
        return trunc
    
    return [[compress(n) for n in v] for v in vertices]

def compress_faces(faces):
    """Compress faces sorted by color, which are converted to rgb565"""
    # [(i, j, k), ...]
    indices = []
    # [(i, rgb565), ...]
    colors = []

    def rgb565(r, g, b):
        return (r >> 3, g >> 2, b >> 3)

    for ((r, g, b), triangles) in faces.items():
        colors.append((len(indices), rgb565(r, g, b)))
        indices.extend(triangles)
    
    return indices, colors

def convert_mesh(path):
    """Converts a 3D .ply mesh file at the path specified to C code"""
    def flatten(xss):
        return [x for xs in xss for x in xs]
    
    with open(path, "r") as f:
        vertices, faces = parse_ply(f.read())
    vertices, faces = vertex_color_to_face(vertices, faces)
    vertices = compress_vertices(vertices)
    indices, colors = compress_faces(faces)
    nl = "\n    "

    # Put this generated code in a C source file, then consolidate all the
    # meshes in a header file with each mesh marked as extern
    return f"""
// Origin mesh: {path}
// Converted using scripts/meshgen.py
#include "gpu.h"
#include "num.h"

static const i16 VERTICES[] = {{
    {nl.join(f"{x}, {y}, {z}," for (x, y, z) in vertices)}
}};

static const u16 INDICES[] = {{
    {nl.join(f"{a}, {b}, {c}," for (a, b, c) in indices)}
}};

static const struct ColorRange COLORS[] = {{
    {nl.join(f"{{ {i}, {{ .r={r}, .g={g}, .b={b} }}}}," for (i, (r, g, b)) in colors)}
}};

const struct Mesh NAME_OF_MESH_HERE = {{
    .vertices = VERTICES,
    .indices = INDICES,
    .colors = COLORS,

    .num_vertices = {len(vertices)},
    .num_faces = {sum(len(f) for f in faces.values())},
    .num_colors = {len(colors)},
}};
    """


print(convert_mesh("./assets/x_wing.ply"))