#include "tilemap.h"
#include <stdlib.h>

Tilemap* Tilemap_Create(Tileset* tileset, int map_width, int map_height, int* data) {
    Tilemap* tilemap = (Tilemap*)malloc(sizeof(Tilemap));
    tilemap->tileset = tileset;
    tilemap->map_width = map_width;
    tilemap->map_height = map_height;
    tilemap->data = (int*)malloc(sizeof(int) * map_width * map_height);
    for (int i = 0; i < map_width * map_height; i++) {
        tilemap->data[i] = data[i];
    }
    return tilemap;
}

void Tilemap_Destroy(Tilemap* tilemap) {
    if (tilemap != NULL) {
        if (tilemap->data != NULL) {
            free(tilemap->data);
        }
        free(tilemap);
    }
}

void Tilemap_Draw(Tilemap* tilemap, RenderLayer layer) {
    if (tilemap == NULL || tilemap->tileset == NULL || tilemap->data == NULL) {
        return;
    }

    for (int y = 0; y < tilemap->map_height; y++) {
        for (int x = 0; x < tilemap->map_width; x++) {
            int tile_id = tilemap->data[y * tilemap->map_width + x];
            if (tile_id < 0) continue; // -1 can mean empty tile

            int tile_x = tile_id % tilemap->tileset->tiles_per_row;
            int tile_y = tile_id / tilemap->tileset->tiles_per_row;

            Renderable r;
            r.texture = tilemap->tileset->texture;
            r.sourceRect = (Rectangle){
                tile_x * tilemap->tileset->tile_width,
                tile_y * tilemap->tileset->tile_height,
                tilemap->tileset->tile_width,
                tilemap->tileset->tile_height
            };
            r.position = (Vector2){
                x * tilemap->tileset->tile_width,
                y * tilemap->tileset->tile_height
            };
            r.tint = WHITE;
            r.layer = layer;

            Renderer_AddRenderable(r);
        }
    }
}
