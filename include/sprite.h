#ifndef SPRITE_H
#define SPRITE_H

#include "raylib.h"
#include "renderer.h"

#define MAX_ANIMATIONS 10
#define MAX_FRAMES 20

typedef struct {
    int frame_count;
    int frame_rate;
    Rectangle frames[MAX_FRAMES];
} Animation;

typedef struct {
    Texture2D spritesheet;
    Animation animations[MAX_ANIMATIONS];
    int animation_count;
    int current_animation;
    int current_frame;
    float frame_timer;
} Sprite;

Sprite* Sprite_Create(Texture2D spritesheet);
void Sprite_Destroy(Sprite* sprite);
void Sprite_AddAnimation(Sprite* sprite, Animation animation);
void Sprite_PlayAnimation(Sprite* sprite, int animation_index);
void Sprite_Update(Sprite* sprite);
Renderable Sprite_GetRenderable(Sprite* sprite, Vector2 position, RenderLayer layer, Color tint);

#endif // SPRITE_H
