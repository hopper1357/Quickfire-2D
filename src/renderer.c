#include "renderer.h"
#include <stdlib.h>

Sprite* CreateSprite(const char* texturePath, Vector2 position) {
    Sprite* sprite = (Sprite*)malloc(sizeof(Sprite));
    if (sprite == NULL) {
        TraceLog(LOG_ERROR, "Failed to allocate memory for sprite");
        return NULL;
    }

    sprite->texture = LoadTexture(texturePath);
    if (sprite->texture.id == 0) {
        TraceLog(LOG_ERROR, "Failed to load texture: %s", texturePath);
        free(sprite); // Free the allocated memory
        return NULL;
    }

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
