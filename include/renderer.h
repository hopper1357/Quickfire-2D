#ifndef RENDERER_H
#define RENDERER_H

#include "raylib.h"

typedef struct Sprite {
    Texture2D texture;
    Vector2 position;
    float rotation;
    float scale;
} Sprite;

Sprite* CreateSprite(const char* texturePath, Vector2 position);
void DrawSprite(Sprite* sprite);
void DestroySprite(Sprite* sprite);

#endif // RENDERER_H
