#include "raylib.h"
#include "renderer.h"
#include "sprite.h"

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Sprite Animation Example");
    SetTargetFPS(60);

    // Initialize the renderer
    Renderer_Init();

    // Generate a simple spritesheet
    Image image = GenImageColor(200, 50, BLANK);
    ImageDrawRectangle(&image, 0, 0, 50, 50, RED);
    ImageDrawRectangle(&image, 50, 0, 50, 50, GREEN);
    ImageDrawRectangle(&image, 100, 0, 50, 50, BLUE);
    ImageDrawRectangle(&image, 150, 0, 50, 50, YELLOW);
    Texture2D player_spritesheet = LoadTextureFromImage(image);
    UnloadImage(image);

    // Create a sprite
    Sprite* player_sprite = Sprite_Create(player_spritesheet);

    // Define an animation
    Animation anim;
    anim.frame_count = 4;
    anim.frame_rate = 4;
    anim.frames[0] = (Rectangle){ 0, 0, 50, 50 };
    anim.frames[1] = (Rectangle){ 50, 0, 50, 50 };
    anim.frames[2] = (Rectangle){ 100, 0, 50, 50 };
    anim.frames[3] = (Rectangle){ 150, 0, 50, 50 };

    // Add and play the animation
    Sprite_AddAnimation(player_sprite, anim);
    Sprite_PlayAnimation(player_sprite, 0);

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        Sprite_Update(player_sprite);
        Renderable r = Sprite_GetRenderable(player_sprite, (Vector2){ 100, 100 }, LAYER_GAME, WHITE);
        Renderer_AddRenderable(r);

        // Draw
        Renderer_Begin();
        Renderer_Draw();
        Renderer_End();
    }

    // De-Initialization
    Sprite_Destroy(player_sprite);
    UnloadTexture(player_spritesheet);
    Renderer_Shutdown();
    CloseWindow();

    return 0;
}
