#ifndef RENDERER_H
#define RENDERER_H

#include "raylib.h"

#define MAX_LAYERS 3
#define MAX_RENDERABLES 1024

typedef enum {
    LAYER_BACKGROUND = 0,
    LAYER_GAME,
    LAYER_UI
} RenderLayer;

typedef struct {
    Texture2D texture;
    Vector2 position;
    RenderLayer layer;
} Renderable;

void Renderer_Init(void);
void Renderer_Shutdown(void);
void Renderer_Begin(void);
void Renderer_End(void);
void Renderer_AddRenderable(Renderable* renderable);
void Renderer_Draw(void);

#endif // RENDERER_H
