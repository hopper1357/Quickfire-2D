#include "input.h"

static InputBinding bindings[MAX_ACTIONS];

void Input_Init(void) {
    // Keyboard bindings
    bindings[ACTION_MOVE_UP] = (InputBinding){ .type = INPUT_TYPE_KEY, .binding = KEY_W };
    bindings[ACTION_MOVE_DOWN] = (InputBinding){ .type = INPUT_TYPE_KEY, .binding = KEY_S };
    bindings[ACTION_MOVE_LEFT] = (InputBinding){ .type = INPUT_TYPE_KEY, .binding = KEY_A };
    bindings[ACTION_MOVE_RIGHT] = (InputBinding){ .type = INPUT_TYPE_KEY, .binding = KEY_D };

    // Mouse bindings
    bindings[ACTION_PRIMARY_ATTACK] = (InputBinding){ .type = INPUT_TYPE_MOUSE, .binding = MOUSE_LEFT_BUTTON };

    // Gamepad bindings
    bindings[ACTION_HORIZONTAL_AXIS] = (InputBinding){ .type = INPUT_TYPE_GAMEPAD_AXIS, .binding = GAMEPAD_AXIS_LEFT_X };
    bindings[ACTION_VERTICAL_AXIS] = (InputBinding){ .type = INPUT_TYPE_GAMEPAD_AXIS, .binding = GAMEPAD_AXIS_LEFT_Y };
    // You can also bind gamepad buttons to actions, e.g.:
    // bindings[ACTION_PRIMARY_ATTACK] = (InputBinding){ .type = INPUT_TYPE_GAMEPAD_BUTTON, .binding = GAMEPAD_BUTTON_RIGHT_FACE_DOWN };
}

bool Input_IsActionPressed(GameAction action) {
    InputBinding binding = bindings[action];
    if (binding.type == INPUT_TYPE_KEY) return IsKeyPressed(binding.binding);
    if (binding.type == INPUT_TYPE_MOUSE) return IsMouseButtonPressed(binding.binding);
    if (binding.type == INPUT_TYPE_GAMEPAD_BUTTON) return IsGamepadButtonPressed(0, binding.binding);
    return false;
}

bool Input_IsActionDown(GameAction action) {
    InputBinding binding = bindings[action];
    if (binding.type == INPUT_TYPE_KEY) return IsKeyDown(binding.binding);
    if (binding.type == INPUT_TYPE_MOUSE) return IsMouseButtonDown(binding.binding);
    if (binding.type == INPUT_TYPE_GAMEPAD_BUTTON) return IsGamepadButtonDown(0, binding.binding);
    return false;
}

bool Input_IsActionReleased(GameAction action) {
    InputBinding binding = bindings[action];
    if (binding.type == INPUT_TYPE_KEY) return IsKeyReleased(binding.binding);
    if (binding.type == INPUT_TYPE_MOUSE) return IsMouseButtonReleased(binding.binding);
    if (binding.type == INPUT_TYPE_GAMEPAD_BUTTON) return IsGamepadButtonReleased(0, binding.binding);
    return false;
}

Vector2 Input_GetMousePosition(void) {
    return GetMousePosition();
}

float Input_GetActionValue(GameAction action) {
    InputBinding binding = bindings[action];
    if (binding.type == INPUT_TYPE_GAMEPAD_AXIS) {
        return GetGamepadAxisMovement(0, binding.binding);
    }
    // For digital inputs, we can return 1.0f if the action is down, 0.0f otherwise
    return Input_IsActionDown(action) ? 1.0f : 0.0f;
}
