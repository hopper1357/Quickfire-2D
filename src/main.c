#include "raylib.h"
#include "renderer.h"
#include "input.h"

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Input System Example");
    SetTargetFPS(60);

    // Initialize the renderer and input system
    Renderer_Init();
    Input_Init();

    // Create a player texture
    Image player_image = GenImageColor(50, 50, RED);
    Texture2D player_texture = LoadTextureFromImage(player_image);
    UnloadImage(player_image);

    // Player position
    Vector2 player_position = { screenWidth / 2, screenHeight / 2 };

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        if (Input_IsActionDown(ACTION_MOVE_UP)) player_position.y -= 5;
        if (Input_IsActionDown(ACTION_MOVE_DOWN)) player_position.y += 5;
        if (Input_IsActionDown(ACTION_MOVE_LEFT)) player_position.x -= 5;
        if (Input_IsActionDown(ACTION_MOVE_RIGHT)) player_position.x += 5;

        Renderable r = {
            .texture = player_texture,
            .sourceRect = { 0, 0, 50, 50 },
            .position = player_position,
            .tint = WHITE,
            .layer = LAYER_GAME
        };
        Renderer_AddRenderable(r);

        // Draw
        Renderer_Begin();
        Renderer_Draw();
        Renderer_End();
    }

    // De-Initialization
    UnloadTexture(player_texture);
    Renderer_Shutdown();
    CloseWindow();

    return 0;
}
