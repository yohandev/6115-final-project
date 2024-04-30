#ifndef ASSETS_H
#define ASSETS_H

#include "../gpu.h"

enum AssetIdentifiers {
    ASSET_STAR_DESTROYER_MESH_ID = 0,
    ASSET_ASTEROID_MESH_ID = 1,
};

extern const struct Mesh ASSET_STAR_DESTROYER_MESH;
extern const struct Mesh ASSET_ASTEROID_MESH;

#endif