#include "raylib.h"
#include "input.h"
#include "audio.h" // Include the audio header

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Input and Audio System Example");
    SetTargetFPS(60);

    // Initialize systems
    Input_Init();
    Audio_Init();

    // Load audio assets
    Audio_LoadSound(SOUND_EFFECT_ATTACK, "assets/attack.wav");
    Audio_LoadMusic(MUSIC_TRACK_BACKGROUND, "assets/background.mp3");

    // Play background music
    Audio_PlayMusic(MUSIC_TRACK_BACKGROUND);

    // Create a player rectangle
    Rectangle player = { screenWidth / 2, screenHeight / 2, 50, 50 };

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        Audio_UpdateMusic(); // Update music stream

        // Keyboard movement
        if (Input_IsActionDown(ACTION_MOVE_UP)) player.y -= 5;
        if (Input_IsActionDown(ACTION_MOVE_DOWN)) player.y += 5;
        if (Input_IsActionDown(ACTION_MOVE_LEFT)) player.x -= 5;
        if (Input_IsActionDown(ACTION_MOVE_RIGHT)) player.x += 5;

        // Gamepad analog movement
        player.x += Input_GetActionValue(ACTION_HORIZONTAL_AXIS) * 5.0f;
        player.y += Input_GetActionValue(ACTION_VERTICAL_AXIS) * 5.0f;

        // Mouse or Gamepad teleport and play sound
        if (Input_IsActionPressed(ACTION_PRIMARY_ATTACK) || Input_IsActionPressed(ACTION_GAMEPAD_ATTACK)) {
            Vector2 mousePos = Input_GetMousePosition();
            player.x = mousePos.x - player.width / 2;
            player.y = mousePos.y - player.height / 2;
            Audio_PlaySound(SOUND_EFFECT_ATTACK); // Play attack sound
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleRec(player, RED);
        DrawText("Use WASD, Gamepad Left Stick, or Mouse Click", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    // De-Initialization
    Audio_Close(); // Close the audio system
    CloseWindow();

    return 0;
}
