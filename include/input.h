#ifndef INPUT_H
#define INPUT_H

#include "raylib.h"

typedef enum {
    INPUT_TYPE_KEY,
    INPUT_TYPE_MOUSE,
    INPUT_TYPE_GAMEPAD_BUTTON,
    INPUT_TYPE_GAMEPAD_AXIS
} InputType;

typedef enum {
    ACTION_MOVE_UP,
    ACTION_MOVE_DOWN,
    ACTION_MOVE_LEFT,
    ACTION_MOVE_RIGHT,
    ACTION_PRIMARY_ATTACK,
    ACTION_GAMEPAD_ATTACK,
    ACTION_HORIZONTAL_AXIS,
    ACTION_VERTICAL_AXIS,
    MAX_ACTIONS
} GameAction;

typedef struct {
    InputType type;
    int binding; // Keyboard key, mouse button, gamepad button, or gamepad axis
} InputBinding;

void Input_Init(void);
bool Input_IsActionPressed(GameAction action);
bool Input_IsActionDown(GameAction action);
bool Input_IsActionReleased(GameAction action);
Vector2 Input_GetMousePosition(void);
float Input_GetActionValue(GameAction action);

#endif // INPUT_H
