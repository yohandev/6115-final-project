#ifndef ASTEROIDS_H
#define ASTEROIDS_H

#include "num.h"

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

#define ASTEROIDS_POOL_LEN 256

struct Asteroids {
    vec3 pos[ASTEROIDS_POOL_LEN];
    vec3 rot[ASTEROIDS_POOL_LEN];
};

extern struct Asteroids Asteroids;

void asteroids_init();
void asteroids_step();

#endif