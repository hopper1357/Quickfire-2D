#include "input.h"

static InputBinding bindings[MAX_ACTIONS];

void Input_Init(void) {
    bindings[ACTION_MOVE_UP] = (InputBinding){ .type = INPUT_TYPE_KEY, .binding = KEY_W };
    bindings[ACTION_MOVE_DOWN] = (InputBinding){ .type = INPUT_TYPE_KEY, .binding = KEY_S };
    bindings[ACTION_MOVE_LEFT] = (InputBinding){ .type = INPUT_TYPE_KEY, .binding = KEY_A };
    bindings[ACTION_MOVE_RIGHT] = (InputBinding){ .type = INPUT_TYPE_KEY, .binding = KEY_D };
    bindings[ACTION_PRIMARY_ATTACK] = (InputBinding){ .type = INPUT_TYPE_MOUSE, .binding = MOUSE_LEFT_BUTTON };
}

bool Input_IsActionPressed(GameAction action) {
    if (bindings[action].type == INPUT_TYPE_KEY) {
        return IsKeyPressed(bindings[action].binding);
    } else if (bindings[action].type == INPUT_TYPE_MOUSE) {
        return IsMouseButtonPressed(bindings[action].binding);
    }
    return false;
}

bool Input_IsActionDown(GameAction action) {
    if (bindings[action].type == INPUT_TYPE_KEY) {
        return IsKeyDown(bindings[action].binding);
    } else if (bindings[action].type == INPUT_TYPE_MOUSE) {
        return IsMouseButtonDown(bindings[action].binding);
    }
    return false;
}

bool Input_IsActionReleased(GameAction action) {
    if (bindings[action].type == INPUT_TYPE_KEY) {
        return IsKeyReleased(bindings[action].binding);
    } else if (bindings[action].type == INPUT_TYPE_MOUSE) {
        return IsMouseButtonReleased(bindings[action].binding);
    }
    return false;
}

Vector2 Input_GetMousePosition(void) {
    return GetMousePosition();
}
