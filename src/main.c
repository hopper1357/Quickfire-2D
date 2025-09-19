#include "raylib.h"
#include "input.h"

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Input System Example");
    SetTargetFPS(60);

    // Initialize the input system
    Input_Init();

    // Create a player rectangle
    Rectangle player = { screenWidth / 2, screenHeight / 2, 50, 50 };

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        if (Input_IsActionDown(ACTION_MOVE_UP)) player.y -= 5;
        if (Input_IsActionDown(ACTION_MOVE_DOWN)) player.y += 5;
        if (Input_IsActionDown(ACTION_MOVE_LEFT)) player.x -= 5;
        if (Input_IsActionDown(ACTION_MOVE_RIGHT)) player.x += 5;

        if (Input_IsActionPressed(ACTION_PRIMARY_ATTACK)) {
            Vector2 mousePos = Input_GetMousePosition();
            player.x = mousePos.x - player.width / 2;
            player.y = mousePos.y - player.height / 2;
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleRec(player, RED);
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
