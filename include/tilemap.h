#ifndef TILEMAP_H
#define TILEMAP_H

#include "raylib.h"
#include "renderer.h"

typedef struct {
    Texture2D texture;
    int tile_width;
    int tile_height;
    int tiles_per_row;
} Tileset;

typedef struct {
    Tileset* tileset;
    int map_width;
    int map_height;
    int* data;
} Tilemap;

Tilemap* Tilemap_Create(Tileset* tileset, int map_width, int map_height, int* data);
void Tilemap_Destroy(Tilemap* tilemap);
void Tilemap_Draw(Tilemap* tilemap, RenderLayer layer);

#endif // TILEMAP_H
