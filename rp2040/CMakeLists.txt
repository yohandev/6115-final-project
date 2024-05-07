cmake_minimum_required(VERSION 3.13)

include(pico-sdk/pico_sdk_init.cmake)
project(rp2040_gpu)

# Add RTT logging target
add_subdirectory("lib/pico-stdio-rtt")

# Initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_executable(rp2040_gpu)

pico_generate_pio_header(rp2040_gpu
    ${CMAKE_CURRENT_LIST_DIR}/src/st7789.pio
)
target_sources(rp2040_gpu PRIVATE
    src/main.c
    src/st7789.c
)
include_directories(rp2040_gpu
    ../psoc/GameLogic.cydsn/common
    src/
)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(rp2040_gpu PRIVATE
    pico_stdlib
    pico_stdio_rtt
    hardware_pio
    hardware_interp
)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(rp2040_gpu)