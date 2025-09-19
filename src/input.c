#include "input.h"

static int key_bindings[MAX_ACTIONS];

void Input_Init(void) {
    key_bindings[ACTION_MOVE_UP] = KEY_W;
    key_bindings[ACTION_MOVE_DOWN] = KEY_S;
    key_bindings[ACTION_MOVE_LEFT] = KEY_A;
    key_bindings[ACTION_MOVE_RIGHT] = KEY_D;
}

bool Input_IsActionPressed(GameAction action) {
    return IsKeyPressed(key_bindings[action]);
}

bool Input_IsActionDown(GameAction action) {
    return IsKeyDown(key_bindings[action]);
}

bool Input_IsActionReleased(GameAction action) {
    return IsKeyReleased(key_bindings[action]);
}
