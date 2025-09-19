#include "game.h"
#include "renderer.h"

static Texture2D background_texture;
static Texture2D player_texture;
static Texture2D ui_texture;

static Renderable background;
static Renderable player;
static Renderable ui_element;

void Game_Init(void) {
    // Generate textures
    Image bg_image = GenImageColor(800, 450, BLUE);
    background_texture = LoadTextureFromImage(bg_image);
    UnloadImage(bg_image);

    Image player_image = GenImageColor(50, 50, RED);
    player_texture = LoadTextureFromImage(player_image);
    UnloadImage(player_image);

    Image ui_image = GenImageColor(100, 40, GREEN);
    ui_texture = LoadTextureFromImage(ui_image);
    UnloadImage(ui_image);

    // Create renderables
    background = (Renderable){
        .texture = background_texture,
        .position = {0, 0},
        .layer = LAYER_BACKGROUND
    };

    player = (Renderable){
        .texture = player_texture,
        .position = {100, 100},
        .layer = LAYER_GAME
    };

    ui_element = (Renderable){
        .texture = ui_texture,
        .position = {20, 20},
        .layer = LAYER_UI
    };
}

void Game_Update(void) {
    // Add renderables to the renderer every frame
    Renderer_AddRenderable(&background);
    Renderer_AddRenderable(&player);
    Renderer_AddRenderable(&ui_element);
}

void Game_Draw(void) {
    // This function is no longer responsible for drawing.
    // The Renderer_Draw function handles all drawing.
}

void Game_Shutdown(void) {
    UnloadTexture(background_texture);
    UnloadTexture(player_texture);
    UnloadTexture(ui_texture);
}
