#include "input.h"
#include "json.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> // For fabsf

#define GAMEPAD_AXIS_DEADZONE 0.25f

static InputBinding bindings[MAX_ACTIONS];

// Helper function to get GameAction enum from string
GameAction GetActionFromString(const char* actionStr) {
    if (strcmp(actionStr, "ACTION_MOVE_UP") == 0) return ACTION_MOVE_UP;
    if (strcmp(actionStr, "ACTION_MOVE_DOWN") == 0) return ACTION_MOVE_DOWN;
    if (strcmp(actionStr, "ACTION_MOVE_LEFT") == 0) return ACTION_MOVE_LEFT;
    if (strcmp(actionStr, "ACTION_MOVE_RIGHT") == 0) return ACTION_MOVE_RIGHT;
    if (strcmp(actionStr, "ACTION_PRIMARY_ATTACK") == 0) return ACTION_PRIMARY_ATTACK;
    if (strcmp(actionStr, "ACTION_GAMEPAD_ATTACK") == 0) return ACTION_GAMEPAD_ATTACK;
    if (strcmp(actionStr, "ACTION_HORIZONTAL_AXIS") == 0) return ACTION_HORIZONTAL_AXIS;
    if (strcmp(actionStr, "ACTION_VERTICAL_AXIS") == 0) return ACTION_VERTICAL_AXIS;
    return MAX_ACTIONS; // Invalid action
}

// Helper function to get InputType enum from string
InputType GetInputTypeFromString(const char* typeStr) {
    if (strcmp(typeStr, "KEY") == 0) return INPUT_TYPE_KEY;
    if (strcmp(typeStr, "MOUSE") == 0) return INPUT_TYPE_MOUSE;
    if (strcmp(typeStr, "GAMEPAD_BUTTON") == 0) return INPUT_TYPE_GAMEPAD_BUTTON;
    if (strcmp(typeStr, "GAMEPAD_AXIS") == 0) return INPUT_TYPE_GAMEPAD_AXIS;
    return -1; // Invalid type
}

void LoadDefaultBindings() {
    // Keyboard bindings
    bindings[ACTION_MOVE_UP] = (InputBinding){ .type = INPUT_TYPE_KEY, .binding = KEY_W };
    bindings[ACTION_MOVE_DOWN] = (InputBinding){ .type = INPUT_TYPE_KEY, .binding = KEY_S };
    bindings[ACTION_MOVE_LEFT] = (InputBinding){ .type = INPUT_TYPE_KEY, .binding = KEY_A };
    bindings[ACTION_MOVE_RIGHT] = (InputBinding){ .type = INPUT_TYPE_KEY, .binding = KEY_D };

    // Mouse bindings
    bindings[ACTION_PRIMARY_ATTACK] = (InputBinding){ .type = INPUT_TYPE_MOUSE, .binding = MOUSE_LEFT_BUTTON };

    // Gamepad bindings
    bindings[ACTION_GAMEPAD_ATTACK] = (InputBinding){ .type = INPUT_TYPE_GAMEPAD_BUTTON, .binding = GAMEPAD_BUTTON_RIGHT_FACE_DOWN };
    bindings[ACTION_HORIZONTAL_AXIS] = (InputBinding){ .type = INPUT_TYPE_GAMEPAD_AXIS, .binding = GAMEPAD_AXIS_LEFT_X };
    bindings[ACTION_VERTICAL_AXIS] = (InputBinding){ .type = INPUT_TYPE_GAMEPAD_AXIS, .binding = GAMEPAD_AXIS_LEFT_Y };
}

void Input_Init(void) {
    FILE* fp = fopen("config.json", "r");
    if (fp == NULL) {
        LoadDefaultBindings();
        return;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* json_string = (char*)malloc(file_size + 1);
    fread(json_string, 1, file_size, fp);
    fclose(fp);

    json_string[file_size] = '\0';

    struct json_value_s* root = json_parse(json_string, file_size);
    if (root == NULL) {
        LoadDefaultBindings();
        free(json_string);
        return;
    }

    struct json_object_s* object = json_value_as_object(root);
    if (object == NULL) {
        LoadDefaultBindings();
        free(json_string);
        free(root);
        return;
    }

    struct json_object_element_s* bindings_obj_el = object->start;
    struct json_object_s* bindings_obj = json_value_as_object(bindings_obj_el->value);

    for (struct json_object_element_s* el = bindings_obj->start; el != NULL; el = el->next) {
        GameAction action = GetActionFromString(el->name->string);
        if (action < MAX_ACTIONS) {
            struct json_object_s* binding_details = json_value_as_object(el->value);
            struct json_string_s* type_str = NULL;
            struct json_number_s* binding_num = NULL;

            for (struct json_object_element_s* detail = binding_details->start; detail != NULL; detail = detail->next) {
                if (strcmp(detail->name->string, "type") == 0) {
                    type_str = json_value_as_string(detail->value);
                } else if (strcmp(detail->name->string, "binding") == 0) {
                    binding_num = json_value_as_number(detail->value);
                }
            }

            if(type_str && binding_num) {
                InputType type = GetInputTypeFromString(type_str->string);
                int binding_val = atoi(binding_num->number);
                if (type != -1) {
                    bindings[action] = (InputBinding){ .type = type, .binding = binding_val };
                }
            }
        }
    }

    free(json_string);
    free(root);
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
        float value = GetGamepadAxisMovement(0, binding.binding);
        if (fabsf(value) > GAMEPAD_AXIS_DEADZONE) {
            return value;
        }
        return 0.0f;
    }
    // For digital inputs, we can return 1.0f if the action is down, 0.0f otherwise
    return Input_IsActionDown(action) ? 1.0f : 0.0f;
}
