#include "world.h"

struct Asteroids Asteroids = {};

void asteroids_init() {
    for (usize i = 0; i < ASTEROIDS_POOL_LEN; i++) {
        Asteroids.pos[i] = vec3_rand(100.0);
        Asteroids.rot[i] = vec3_rand(2 * PI);
    }
}

void asteroids_step() {
    // TODO: move the asteroids somehow
}