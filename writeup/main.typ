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
#lorem(200)