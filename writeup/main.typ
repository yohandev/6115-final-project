#import "ieee.typ": ieee

#show: ieee.with(
  title: [6.115 Final Project],
  abstract: [
    This project involves the implementation of a handheld video-game console. It utilizes two ARM Cortex (M3 and M0+) processors to simulate a three-dimensional virtual world (e.g. a physics engine) and render it to an LCD display. Namely, a Cypress "PSoC Stick" CY8CKIT-059 is responsible for the game logic and user inputs while an RP2040 microcontroller draws and pushes frames to the display. Embedded software techniques as covered in 6.115 lecture and independently researched are employed to achieve all of this at a playable framerate despite using modest microcontrollers.
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
Modern video-games simulate and display complex environments in realtime, necessitating high-end hardware with several gigabytes of volatile memory and a considerable multicore processor. In comparison, microcontrollers rarely push a megabyte of random-access memory (RAM) with one or two underpowered cores (in comparison to a desktop system). The PSoC 5 boasts 64kB of system RAM @psocdatasheet, or just under half a second of uncompressed audio as stored on a CD; its single-core ARM Cortex-M3 processor would not even compare to any desktop CPU, as it lacks a floating-point unit @cortexm (FLOPS do not apply here!).

Despite this, game designers have been creating compeling experiences on low-end hardware for decades (or in the case of retro consoles, it was the best they had at the time)! In employing software tricks or being clever with their artistic directions, titles like like _Zelda: Breath of the Wild (2017)_ and _DOOM (1993)_ deliver much more than what their "minimum specs" permit at face value. Likewise, implementing a 3D video-game on hardware that costs several dollars poses an interesting challenge of the same order.

This final project implements a dogfighting video-game similar to the game-mode in _Star Wars: Battlefront (2015)_, but entirely on embedded hardware. It is, of course, not be as content-rich as its AAA counterpart but still features the basic gameplay elements like controlling your spaceship around an Imperial Star Destroyer and asteroids. An additional microcontroller, the RP2040, is introduced to offload the task of rendering 3D graphics; its processor is comparable to the PSoC but features slightly more SRAM to account for frame and depth buffers (more on this later).

= Game Controller Hardware
Due to the amount of hardware required for this project, and the desired form factor of a small handheld console, this project involves a PCB designed in KiCAD which houses all the required components. This PCB was milled on the BantamTools CNC in EDS using a 1/32" and 1/64" endmill.
#figure(image("images/schematic.png"), caption: "Schematic of the game controller featuring user inputs, two ARM microcontrollers and communications between the two.")

The game controller consists of two push buttons, an analog joystick and  an ST7735 TFT display. In addition to this, a PSoC "Stick" 5 LP is slotted on top of header pins. The Xiao RP2040 is soldered directly on the PCB to breakout the debug pins on its backside; this is small investment given the board's very cheap price tag. As shown in the schematic above, all inputs are routed to the PSoC and the TFT screen is wired directly to the RP2040. The two microcontrollers communicate over a simplex SPI line (the PSoC is the "master" and RP2040 is the "slave"). Two resistive dividers are incorporated to shift the voltage from the PSoC's 5V to the RP2040's 3.3V. A third line, "V-SYNC" is added to throttle communications between the two; the RP2040 lowers this line whenever it has enough or too much data to process.

#figure(image("images/pcb_3d.png", width: 50%), caption: "Render of the two-layer PCB for the game controller. Most connections are on the backside which eliminates the need for vias and reduces complexity.")

Finally, a 3D printed case is suited to this PCB to protect the internal components and improve the design aesthetics of the project. It was designed in the Shapr3D CAD program, and printed out of PLA on a Bambu P1S.

#figure(image("images/casing.png", width: 50%), caption: "Render of the 3D printed case.")

The USB-A connector of the PSoC is exposed through a gap in the case to power and program the device. On the back, 3 header pins (GND, SWDIO, SWDCLK) are exposed to program the RP2040 using ARM's Serial Wire Debug (SWD) interface. During this project, I used another Rasperry Pi Pico as a debugger.

= Controller Firmware
Much of the interfacing with input devices (joystick, buttons) is handled in hardware using the PSoC's modules. The buttons are internally connected to a pull-up resistor and debouncer circuit that triggers an interrupt. The analog joystick has similar circuitry for its Z axis (it, too, features a push button); the horizontal and vertical inputs are treated as two potentiometers and read using the PSoC's built-in 12 bit SAR ADCs. All of these are implemented in hardware using PSoC Creator 3.3, and an additional utility file was written to facilitate initialization and maintenance of these modules: `gamepad.h`.
```C
struct Gamepad {
    struct {
        f32 x;
        f32 y;
        bool sel;
    } joystick;
    bool buttons[2];
};

extern struct Gamepad Gamepad;

void gamepad_init();
void gamepad_poll();
```
Utility files like these are common throughout the codebase of this project to abstract away all the auto-generated files that pollute the global namespace.

#figure(image("images/firmware.png", width: 100%), caption: "Screen capture of the hardware components as designed in PSoC Creator 3.3.")

Next, a hardware timer is utilized to measure the time between frames. This is absolutely necessary in a real-time video game because the frame rate will never be perfectly steady, and game logic shouldn't be time independent (e.g. your character shouldn't move faster if your system can achieve higher frame rates). Unfortunately, accessing the PSoC's SysTick wasn't as trivial as other ARM microcontrollers so a rather "hacky" approach was taken instead. It consists of an 8-bit hardware timer that would overflow every \~500ms, but is read and reset through status and control registers, respectively. The assumption is that frames' computation time will never exceed half a second, and delta times can be computed without the need for a global clock source (i.e. SysTick). This is again abstracted through a utility file, `time.h`.
```c
struct Time {
    f32 dt;
    f32 time;
};

extern struct Time Time;
    
void time_init();
void time_step();
```

Finally, a UART component is included to enable logging. Its RX and TX pins are routed to the PSoC's programmer, as specificed in the data sheet, and works as a serial to USB bridge. So, serial output and program flashing/debugging happen both over the same USB port.

= Game Logic
The PSoC is responsible for all user inputs, program management and "business logic" which involves initializing and updating all the game entities. Currently, there are three entities: the camera, an X-Wing spaceship controlled by the player, and a Star Destroyer spaceship. Several control schemes were implemented and experimented upon for the player's spaceship. The intention was to achieve something that felt arcade-like but still grounded in reality (whatever that means for Star Wars goes, anyways). The final approach for updating the spaceship's position is as follows: the joystick inputs X and Y correspond to yaw and pitch respectively. A change in yaw also results in the spaceship banking, which snaps back when the user releases the X joystick to its center position. This is implemented using quaternions to avoid weird rotation behaviours or gimbal lock. Finally, the spaceship's position is incremented by its forward vector times some speed component.

None of this would feel satisfying without a solid camera controller. Thus, time was also dedicated into perfecting a third-person camera follower. The final approach is relatively simple: the camera's rotation and position is lerped from what it is currently to the spaceship's pose offseted by some distance along its forward axis.

$ p_"cam"[n] =  p_"cam"[n - 1] + alpha times (p_"spaceship" - d times hat(k)) $

For some $0 < alpha < 1$ which dampens the rate at which the camera follows the player. This gives the controls a feel of inertia and speed.

= Storing 3D Mesh Assets
Due to the already computationally-intense nature of this project, low-poly meshes were chosen to reduce the amount of data which needs to be processed and stored. The Star Destroyer model @stardestroyer was found online with a permissive license and adapted in Blender to just 2,500 vertices and under 4,000 faces.

#figure(image("images/star_destroyer.png", width: 100%), caption: "Render of the Star Destroyer 3D model.")

Similarly, the X-Wing model @xwing was decimated to just 1,200 vertices and 2,300 triangles.

#figure(image("images/x_wing.png", width: 50%), caption: "Render of the X-Wing 3D model.")

Despite reasonable efforts in reducing the amount of geometry, a 3D model such as these still require too much memory for the microcontrollers to store. A binary glTF export (this format is especially compact and used for delivering 3D models across the web) of the Star Destroyer is 358kB. In contrast, the PSoC has 256kB of flash and 64kB of SRAM. So, storing these 3D models using existing formats would consume more than all of the memory available to this system.

Thus, this project involved a custom format for storing and delivering 3D meshes. It is as follows:
```C
// Meshes overview:
// Vertices (max of 65536) are stored in 8.8 fixed point (half of normal)
// Indices are therefore 16-bit integers
// No textures, but ranges of triangles (its indices) can take on a different color
//
// Consideration must be made to maximize this representation, e.g. the biggest mesh
// in the game should ideally have vertices almost maxing out the 8.8 fixed point. Also,
// because there is no per-vertex color, meshes with lots of similar color are preferred.
struct Mesh {
    const fixed16* vertices;
    const u16* indices;
    const struct ColorRange {
        u16 start;          // Starting face index where this color takes effect
        rgb rgb;
    }* colors;

    usize num_vertices;
    usize num_faces;
    usize num_colors;
};
```
Information common to many mesh formats is thrown away: per-vertex normals and colors, texture mapping, etc. Only the essentials are kept and heavily optmized for low-poly meshes. Namely, only 65,536 vertices are possible due to the bit-width of the indices. Note that a mesh is a surface representation of a 3D object defined by vertices connected through triangular faces -- the indices list define which triad of vertices form a face. Moreover, the vertices are stored using fixed point 16-bit numbers rather than floating point 32-bit numbers or, worse, an ASCII representation of their position. Texture information is discarded but flat colors are still possible; these, too, are optimized using a variant of run-length encoding. Faces that share a color are grouped together in the indices list, so only the change of color needs to be encoded in the data format.

A Python script was developed to convert meshes the Stanford (`.ply`) format to a `.h` C header file while also compressing the data as aforementioned. Overall, the Star Destroyer mesh is reduced to just 38,454 bytes in program memory which is a 90% reduction from the original `.glb` file.

= Software Rasterizer
The graphics of the game are handled almost entirely by the RP2040. Although its capabilities are simlar to the PSoC (both are low-end ARM Cortex processors), it features slightly more SRAM (254kB) to account for two screen buffers. An entire screen buffer is needed because nearly every pixel is overwritten each frame in 3D graphics and two are preferred to avoid visual artifacts of the next frame being rendered as it is being displayed (one is on-screen and the other being currently rendered is off-screen). The RP2040 offers two high-level functionalities to the PSoC: render a given mesh to some screen buffer, and push a screen buffer to the TFT display. All meshes and commands are authored by the PSoC (though meshes are cached on the RP2040 rather than uploaded each frame since its SRAM capacity is permissive). The memory distribution for the RP2040 is shown below:
- 264kB usable SRAM:
  - `4kB Bank #0`: Core 0 Stack + Locals
  - `4kB Bank #1`: Core 1 Stack + Locals
  - `64kB Bank #0`: Framebuffer 0, Z-Buffer
  - `64kB Bank #1`: Framebuffer 1
  - `64kB Bank #2`: Uploaded meshes
  - `64kB Bank #3`: Instances queue

== TFT Drivers
This project makes use of the ST7735 LCD TFT display. It was chosen over other displays because of its low pixel density of 128 by 160. This lets two screen buffers be stored in the SRAM of the RP2040. The drivers for the display were adapted from the example in the `pico-examples` repository @picoexample. Some notable improvements over this library include the usage of direct memory access (DMA) to offload the task of pushing memory data to the SPI peripherals. So, the CPU can render the next frame while the current frame is being pushed to the display, concurrently. Overall, these drivers achieve frame rates well over 60 FPS and no visual flickering with an SPI data throughput of around 62.5Mbps.

== Graphics Pipeline
Rendering a frame begins with the PSoC, which waits for the `V-SYNC` line to go high. This is triggered by the RP2040 to notify the PSoC that it is ready for more commands to be sent -- game logic and rendering happen concurrently on the two microcontrollers, but graphics are likely slower and data would be lost or corrupted if not throttled. On the first frame, during setup, the PSoC uploads meshes to the RP2040 (it would have been possible to store the meshes directly on the RP2040, but doing it this way gets the point across that the RP2040 is "just" a peripheral). On any other frame, the PSoC issues `draw_instanced` calls. This involves sending the ID of the mesh to be drawn, as well as every position and orientation of the instances of that mesh. The RP2040 does not do its own state management, so the PSoC must also ask for the framebuffers to be swapped and the TFT display updated.

Once the RP2040 has received its commands, the actual rendering can begin. 
  
- How it works:
  - PSoC waits for `GPU-ready` signal to go high, signaling that the previous frame is complete
  - PSoc sends all the commands for this frame (ignorign `GPU-ready` if it goes low during this process)
  - RP2040 queues all these commands in `64kB Bank #3` using DMA and either PIO or SPI slave
  - Each core will take a command (e.g. an instance to draw) from the queue and render it
    - Can't transform the vertices in-place in the uploaded meshes cache
    - Instead, each core has a small cache of vertices (a hash-map keyed by the vertex index) of transformed vertices that it references; i.e. it rasterizes _while_ transforming vertices.
- 64-bit multiplication is expensive, but 32-bit is very cheap thanks for hardware multiplier. With 16-bit 8.8 fixed point, I can do multiplication in a 32-bit register. Problem: translations might exceed this. So, every transformation (scale, rotation) is applied using a 16-bit fixed point matrix, as per usual. Then the result is kept in 32-bit 16.16 fixed point and the translation component is added.
- Good resources:
  - [Fixed point rasterizer](https://github.com/halcy/rasterizer2/tree/master)
  - []

== Drawing Triangles
(Go over the chosen algorithm using barycentric coordinates, benchmarks over implementations (floating point, fixed point, hardware interpolator). Note that fixed point implementation inherently has subpixel precision. See rasterizer.c)

= Development Rasterizer