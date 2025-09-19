#include "sprite.h"
#include <stdlib.h>

Sprite* Sprite_Create(Texture2D spritesheet) {
    Sprite* sprite = (Sprite*)malloc(sizeof(Sprite));
    sprite->spritesheet = spritesheet;
    sprite->animation_count = 0;
    sprite->current_animation = -1;
    sprite->current_frame = 0;
    sprite->frame_timer = 0.0f;
    return sprite;
}

void Sprite_Destroy(Sprite* sprite) {
    if (sprite != NULL) {
        free(sprite);
    }
}

void Sprite_AddAnimation(Sprite* sprite, Animation animation) {
    if (sprite != NULL && sprite->animation_count < MAX_ANIMATIONS) {
        sprite->animations[sprite->animation_count++] = animation;
    }
}

void Sprite_PlayAnimation(Sprite* sprite, int animation_index) {
    if (sprite != NULL && animation_index < sprite->animation_count) {
        if (sprite->current_animation != animation_index) {
            sprite->current_animation = animation_index;
            sprite->current_frame = 0;
            sprite->frame_timer = 0.0f;
        }
    }
}

void Sprite_Update(Sprite* sprite) {
    if (sprite != NULL && sprite->current_animation != -1) {
        Animation* anim = &sprite->animations[sprite->current_animation];
        sprite->frame_timer += GetFrameTime();
        if (sprite->frame_timer >= 1.0f / anim->frame_rate) {
            sprite->frame_timer = 0.0f;
            sprite->current_frame = (sprite->current_frame + 1) % anim->frame_count;
        }
    }
}

Renderable Sprite_GetRenderable(Sprite* sprite, Vector2 position, RenderLayer layer, Color tint) {
    Renderable r = {0};
    if (sprite != NULL && sprite->current_animation != -1) {
        Animation* anim = &sprite->animations[sprite->current_animation];
        r.texture = sprite->spritesheet;
        r.sourceRect = anim->frames[sprite->current_frame];
        r.position = position;
        r.tint = tint;
        r.layer = layer;
    }
    return r;
}
