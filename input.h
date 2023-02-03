// "input.h" for controls
#ifndef INCLDUE_INPUT_H
#define INCLUDE_INPUT_H

#include "mathier.h"
#include "src/libs/raylib.h"

// MX - mousex, etc | MD - mouse down, etc | R = right, nothing = left
extern int input_MX,
	       input_MY,
 	       input_MD,
	       input_MRD;

typedef enum Inputs {
    Inputs_CONTROL_PAUSE  = 1,
    Inputs_CONTROL_JUMP   = 2,
    Inputs_CONTROL_CROUCH = 3,
    Inputs_CONTROL_LEFT   = 4,
    Inputs_CONTROL_MOVE_A = 5,
    Inputs_CONTROL_RIGHT  = 6,
    Inputs_CONTROL_MOVE_B = 7,
    Inputs_KEYBIND_PAUSE  = KEY_ESCAPE,
    Inputs_KEYBIND_JUMP   = KEY_SPACE,
    Inputs_KEYBIND_CROUCH = KEY_LEFT_SHIFT,
    Inputs_KEYBIND_LEFT   = KEY_A,
    Inputs_KEYBIND_RIGHT  = KEY_D,
    Inputs_GAMEPAD_PAUSE  = GAMEPAD_BUTTON_MIDDLE_RIGHT,
    Inputs_GAMEPAD_JUMP   = GAMEPAD_BUTTON_RIGHT_FACE_DOWN,
    Inputs_GAMEPAD_CROUCH = GAMEPAD_BUTTON_LEFT_TRIGGER_1,
    // strafing is determied by joystick, but for dpad gamers....
    Inputs_GAMEPAD_LEFT   = GAMEPAD_BUTTON_LEFT_FACE_LEFT,
    Inputs_GAMEPAD_RIGHT  = GAMEPAD_BUTTON_LEFT_FACE_RIGHT
} Inputs;

int input_CheckDown(int control);

int input_GetButtonDown();

void input_UpdateMouseVariables();

VectorInt2 input_GetMXY();

void input_DrawCursor();

#endif

