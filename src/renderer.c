#include "renderer.h"
#include <string.h> // For memset

#include <stdlib.h>

static Renderable render_layers[MAX_LAYERS][MAX_RENDERABLES];
static int render_counts[MAX_LAYERS];

void Renderer_Init(void) {
    for (int i = 0; i < MAX_LAYERS; i++) {
        render_counts[i] = 0;
    }
}

void Renderer_Shutdown(void) {
    // Nothing to do here for now, but we might need to free stuff later
}

void Renderer_Begin(void) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
}

void Renderer_End(void) {
    EndDrawing();
}

void Renderer_AddRenderable(Renderable renderable) {
    if (render_counts[renderable.layer] < MAX_RENDERABLES) {
        render_layers[renderable.layer][render_counts[renderable.layer]++] = renderable;
    }
}

void Renderer_Draw(void) {
    for (int i = 0; i < MAX_LAYERS; i++) {
        for (int j = 0; j < render_counts[i]; j++) {
            Renderable r = render_layers[i][j];
            Rectangle destRect = { r.position.x, r.position.y, r.sourceRect.width, r.sourceRect.height };
            DrawTexturePro(r.texture, r.sourceRect, destRect, (Vector2){ 0, 0 }, 0, r.tint);
        }
        // Reset for next frame
        render_counts[i] = 0;
    }
}
