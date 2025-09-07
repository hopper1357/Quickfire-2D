#include "renderer.h"
#include <stdlib.h>

Sprite* CreateSprite(const char* texturePath, Vector2 position) {
    Sprite* sprite = (Sprite*)malloc(sizeof(Sprite));
    if (sprite == NULL) {
        return NULL;
    }

    sprite->texture = LoadTexture(texturePath);
    sprite->position = position;
    sprite->rotation = 0.0f;
    sprite->scale = 1.0f;

    return sprite;
}

void DrawSprite(Sprite* sprite) {
    if (sprite == NULL) {
        return;
    }

    DrawTextureEx(sprite->texture, sprite->position, sprite->rotation, sprite->scale, WHITE);
}

void DestroySprite(Sprite* sprite) {
    if (sprite == NULL) {
        return;
    }

    UnloadTexture(sprite->texture);
    free(sprite);
}
