#import "ieee.typ": ieee

#show: ieee.with(
  title: [6.115 Final Project],
  abstract: [
    This project involves the implementation of a handheld video-game console. It will utilize two ARM Cortex (M3 and M0+) processors to simulate a three-dimensional virtual world (e.g. a physics engine) and render it to an LCD display. Namely, a Cypress "PSoC Stick" CY8CKIT-059 is responsible for the game logic and user inputs while an RP2040 microcontroller draws and pushes frames to the display. Embedded software techniques as covered in 6.115 lecture and independently researched will be employed to achieve all of this at a playable framerate despite using modest microcontrollers. 
  ],
  authors: (
    (
      name: "Yohan Guyomard",
      organization: [Massachusetts Institute of Technology],
      location: [Cambridge, MA],
      email: "yohang@mit.edu"
    ),
  ),
  bibliography: bibliography("refs.bib"),
)

= Introduction
#lorem(200)

= Game Controller Hardware
(Go over the PCB)
#figure(image("images/schematic.png"), caption: "Schematic of the game controller featuring user inputs, two ARM microcontrollers and communications between the two.")

#figure(image("images/pcb_3d.png", width: 50%), caption: "Render of the two-layer PCB for the game controller. Most connections are on the backside which eliminates the need for vias and reduces complexity.")

#lorem(200)

= Controller Firmware
(Go over the PSoC schematic; button debouncing, potentiometer, interrupts, etc.)
#lorem(200)

= Development Environment
(Go over the UART on the PSoC and SWD on the RP2040)
(Talk about using Pico SDK, RTT for logging and another Pico as a debugger)
#lorem(200)

= Storing 3D Mesh Assets
(Go over how a single mesh, even if low poly, complete exceeds the memory limitations in common formats, event glTF)

= Software Rasterizer
- Memory distribution:
  - `4kB Bank #0`: Core 0 Stack + Locals
  - `4kB Bank #1`: Core 1 Stack + Locals
  - `64kB Bank #0`: Framebuffer 0, Z-Buffer
  - `64kB Bank #1`: Framebuffer 1
  - `64kB Bank #2`: Uploaded meshes
  - `64kB Bank #3`: Instances queue
- How it works:
  - PSoC waits for `GPU-ready` signal to go high, signaling that the previous frame is complete
  - PSoc sends all the commands for this frame (ignorign `GPU-ready` if it goes low during this process)
  - RP2040 queues all these commands in `64kB Bank #3` using DMA and either PIO or SPI slave
  - Each core will take a command (e.g. an instance to draw) from the queue and render it
    - Can't transform the vertices in-place in the uploaded meshes cache
    - Instead, each core has a small cache of vertices (a hash-map keyed by the vertex index) of transformed vertices that it references; i.e. it rasterizes _while_ transforming vertices.
- 64-bit multiplication is expensive, but 32-bit is very cheap thanks for hardware multiplier. With 16-bit 8.8 fixed point, I can do multiplication in a 32-bit register. Problem: translations might exceed this. So, every transformation (scale, rotation) is applied using a 16-bit fixed point matrix, as per usual. Then the result is kept in 32-bit 16.16 fixed point and the translation component is added.

== Drawing Triangles
(Go over the chosen algorithm using barycentric coordinates, benchmarks over implementations (floating point, fixed point, hardware interpolator). Note that fixed point implementation inherently has subpixel precision. See rasterizer.c)