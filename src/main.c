#include "raylib.h"
#include "renderer.h"
#include "tilemap.h"

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Tilemap Example");
    SetTargetFPS(60);

    // Initialize the renderer
    Renderer_Init();

    // Generate a simple tileset (2x2 tiles of different colors)
    Image image = GenImageColor(32, 32, BLANK);
    ImageDrawRectangle(&image, 0, 0, 16, 16, RED);
    ImageDrawRectangle(&image, 16, 0, 16, 16, GREEN);
    ImageDrawRectangle(&image, 0, 16, 16, 16, BLUE);
    ImageDrawRectangle(&image, 16, 16, 16, 16, YELLOW);
    Texture2D tileset_texture = LoadTextureFromImage(image);
    UnloadImage(image);

    // Create a tileset
    Tileset tileset = {
        .texture = tileset_texture,
        .tile_width = 16,
        .tile_height = 16,
        .tiles_per_row = 2
    };

    // Define map data
    int map_data[MAP_WIDTH * MAP_HEIGHT] = {
        0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
        1, 2, 1, 2, 1, 2, 1, 2, 1, 2,
        0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
        1, 2, 1, 2, 1, 2, 1, 2, 1, 2,
        0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
        1, 2, 1, 2, 1, 2, 1, 2, 1, 2,
        0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
        1, 2, 1, 2, 1, 2, 1, 2, 1, 2,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3
    };

    // Create a tilemap
    Tilemap* tilemap = Tilemap_Create(&tileset, MAP_WIDTH, MAP_HEIGHT, map_data);

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        // (Nothing to update for this example)

        // Draw
        Renderer_Begin();
        Tilemap_Draw(tilemap, LAYER_BACKGROUND);
        Renderer_Draw();
        Renderer_End();
    }

    // De-Initialization
    Tilemap_Destroy(tilemap);
    UnloadTexture(tileset_texture);
    Renderer_Shutdown();
    CloseWindow();

    return 0;
}
