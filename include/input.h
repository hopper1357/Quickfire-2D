#ifndef INPUT_H
#define INPUT_H

#include "raylib.h"

typedef enum {
    INPUT_TYPE_KEY,
    INPUT_TYPE_MOUSE
} InputType;

typedef enum {
    ACTION_MOVE_UP,
    ACTION_GOTO_ACTION,
    ACTION_MOVE_DOWN,
    ACTION_MOVE_LEFT,
    ACTION_MOVE_RIGHT,
    ACTION_PRIMARY_ATTACK,
    MAX_ACTIONS
} GameAction;

typedef struct {
    InputType type;
    int binding; // Keyboard key or mouse button
} InputBinding;

void Input_Init(void);
bool Input_IsActionPressed(GameAction action);
bool Input_IsActionDown(GameAction action);
bool Input_IsActionReleased(GameAction action);
Vector2 Input_GetMousePosition(void);

#endif // INPUT_H
