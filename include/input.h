#ifndef INPUT_H
#define INPUT_H

#include "raylib.h"

typedef enum {
    ACTION_MOVE_UP,
    ACTION_MOVE_DOWN,
    ACTION_MOVE_LEFT,
    ACTION_MOVE_RIGHT,
    MAX_ACTIONS
} GameAction;

void Input_Init(void);
bool Input_IsActionPressed(GameAction action);
bool Input_IsActionDown(GameAction action);
bool Input_IsActionReleased(GameAction action);

#endif // INPUT_H
