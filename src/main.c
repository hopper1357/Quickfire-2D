#include "raylib.h"
#include "core.h"
#include "renderer.h"
#include "input.h"
#include "audio.h"
#include "physics.h"
#include "scripting.h"
#include "game.h"
#include "editor.h"
#include "data.h"

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib JS Game Engine");
    SetTargetFPS(60);

    Core_Init();
    Renderer_Init();
    Input_Init();
    Audio_Init();
    Physics_Init();
    Scripting_Init();
    Game_Init();
    Editor_Init();
    Data_Init();

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        Core_Update();
        Input_Update();
        Audio_Update();
        Physics_Update();
        Scripting_Update();
        Game_Update();
        Editor_Update();

        // Draw
        Renderer_Begin();
        Renderer_Draw();
        Renderer_End();
    }

    // De-Initialization
    Data_Shutdown();
    Editor_Shutdown();
    Game_Shutdown();
    Scripting_Shutdown();
    Physics_Shutdown();
    Audio_Shutdown();
    Input_Shutdown();
    Renderer_Shutdown();
    Core_Shutdown();

    CloseWindow();

    return 0;
}
