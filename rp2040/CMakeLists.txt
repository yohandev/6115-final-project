cmake_minimum_required(VERSION 3.13)

include(pico-sdk/pico_sdk_init.cmake)
project(rp2040_gpu)

# Add RTT logging target
add_subdirectory("lib/pico-stdio-rtt")

# Initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_executable(rp2040_gpu
    src/main.c
)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(rp2040_gpu
    pico_stdlib
    pico_stdio_rtt
)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(rp2040_gpu)