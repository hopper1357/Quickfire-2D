#include "raylib.h"
#include "renderer.h"
#include <stddef.h>

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib JS Game Engine");

    if (!IsWindowReady()) {
        TraceLog(LOG_ERROR, "Failed to initialize window");
        return 1;
    }

    Sprite* logo = CreateSprite("assets/raylib_logo.png", (Vector2){0, 0});
    if (logo == NULL) {
        TraceLog(LOG_ERROR, "Failed to create sprite");
        CloseWindow();
        return 1;
    }

    logo->position = (Vector2){
        (screenWidth / 2) - (logo->texture.width / 2),
        (screenHeight / 2) - (logo->texture.height / 2)
    };

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawSprite(logo);
        EndDrawing();
    }

    DestroySprite(logo);
    CloseWindow();

    return 0;
}
