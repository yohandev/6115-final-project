#include "world.h"
#include "gpu.h"

struct World World = {};

void world_init() {
    // Asteroids
    for (usize i = 0; i < WORLD_ASTEROIDS_POOL_LEN; i++) {
        World.asteroids.pos[i] = vec3_rand(100.0);
        World.asteroids.rot[i] = vec3_rand(2 * PI);
    }

    // Star Destroyer
    World.star_destroyer.pos = (vec3){ .x=20, .y=10, .z=20 };
}

void world_step() {
    // TODO: move the asteroids somehow
}