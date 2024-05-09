#ifndef WORLD_H
#define WORLD_H

#include "common/num.h"

// TODO:
// Overview of asteroids field algorithm:
//  - ASTEROIDS_CHUNK_SIZE: World space is divided in a discrete grid of this size
//  - ASTEROIDS_CHUNK_NUM_OBJECTS: Number of asteroids in a single chunk
//  - ASTEROIDS_GRID_POOL_LEN: Amount of grid cells that are allocated and simulated at once
// There are more objects in the asteroid field than storage space on the PSoC and that is
// feasible to simulate at once. So, the asteroid field is partitioned in a grid and a fixed
// number of asteroids are "spawned" at once. Whenever the player enters a new grid cell, it
// will replace the grid cell that is farthest from the player. Asteroids within a grid cell
// are generated using Poison disc sampling (and cell's position is hashed and used as the RNG
// seed), so they will appear aesthetically distributed and (more importantly) are deterministic.
//
// The asteroids' rotation, size, and drift (they move and rotate slightly) are generated using
// the same RNG. Since it is seeded, this should all be deterministic.
// #define ASTEROIDS_GRID_SIZE 256 // (meters)
// #define ASTEROIDS_GRID_POOL_LEN 

#define WORLD_ASTEROIDS_POOL_LEN 512

struct World {
    struct Camera {
        vec3f pos;
        vec3f rot;
    } camera;

    struct Asteroids {
        vec3f pos[WORLD_ASTEROIDS_POOL_LEN];
        vec3f rot[WORLD_ASTEROIDS_POOL_LEN];
        f32 scale[WORLD_ASTEROIDS_POOL_LEN];
    } asteroids;

    struct StarDestroyer {
        vec3f pos;
        vec3f rot;
    } star_destroyer;
};

extern struct World World;

void world_init();
void world_step();

#endif