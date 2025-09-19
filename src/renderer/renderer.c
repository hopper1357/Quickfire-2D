#include "renderer.h"
#include <string.h> // For memset

static Renderable* render_layers[MAX_LAYERS][MAX_RENDERABLES];
static int render_counts[MAX_LAYERS];

void Renderer_Init(void) {
    for (int i = 0; i < MAX_LAYERS; i++) {
        render_counts[i] = 0;
        for (int j = 0; j < MAX_RENDERABLES; j++) {
            render_layers[i][j] = NULL;
        }
    }
}

void Renderer_Shutdown(void) {
    // Nothing to do here for now
}

void Renderer_Begin(void) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
}

void Renderer_End(void) {
    EndDrawing();
}

void Renderer_AddRenderable(Renderable* renderable) {
    if (renderable != NULL && render_counts[renderable->layer] < MAX_RENDERABLES) {
        render_layers[renderable->layer][render_counts[renderable->layer]++] = renderable;
    }
}

void Renderer_Draw(void) {
    for (int i = 0; i < MAX_LAYERS; i++) {
        for (int j = 0; j < render_counts[i]; j++) {
            Renderable* r = render_layers[i][j];
            if (r != NULL) {
                DrawTexture(r->texture, r->position.x, r->position.y, WHITE);
            }
        }
        // Reset for next frame
        render_counts[i] = 0;
    }
}
