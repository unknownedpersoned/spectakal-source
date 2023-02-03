// "input.c" for controls
#include "../input.h"

#include "../game.h"
#include "../mathier.h"
#include "libs/raylib.h"

// MX - mousex, etc | MD - mouse down, etc | R = right, nothing = left
int input_MX = (int)(Global_ResX / 2),
	input_MY = (int)(Global_ResY / 2),
    input_RMX,
    input_RMY,
	input_MD,
	input_MRD;

static int g(int a){return IsGamepadButtonDown(0,a);}
static int k(int a){return IsKeyDown(a);}

int input_CheckDown(int control) {
    switch (control) {
        case Inputs_CONTROL_MOVE_A:return(input_CheckDown(Inputs_CONTROL_LEFT)||input_CheckDown(Inputs_CONTROL_RIGHT));
        case Inputs_CONTROL_MOVE_B:return(input_CheckDown(Inputs_CONTROL_LEFT)&&input_CheckDown(Inputs_CONTROL_RIGHT)) ;
        case Inputs_CONTROL_LEFT:return(k(Inputs_KEYBIND_LEFT)||g(Inputs_GAMEPAD_LEFT));
        case Inputs_CONTROL_RIGHT:return(k(Inputs_KEYBIND_RIGHT)||g(Inputs_GAMEPAD_RIGHT));
        case Inputs_CONTROL_JUMP:return(k(Inputs_KEYBIND_JUMP)||g(Inputs_GAMEPAD_JUMP));
        case Inputs_CONTROL_CROUCH:return(k(Inputs_KEYBIND_CROUCH)||g(Inputs_GAMEPAD_CROUCH));
        case Inputs_CONTROL_PAUSE:return(k(Inputs_KEYBIND_PAUSE)||g(Inputs_GAMEPAD_PAUSE));
        default: return 0;
    }
}

int input_GetButtonDown() {
    if (input_CheckDown(Inputs_CONTROL_LEFT))   return Inputs_CONTROL_LEFT;
    if (input_CheckDown(Inputs_CONTROL_RIGHT))  return Inputs_CONTROL_RIGHT;
    if (input_CheckDown(Inputs_CONTROL_CROUCH)) return Inputs_CONTROL_CROUCH;
    if (input_CheckDown(Inputs_CONTROL_JUMP))   return Inputs_CONTROL_JUMP;
    if (input_CheckDown(Inputs_CONTROL_PAUSE))  return Inputs_CONTROL_PAUSE;
    return 0;
}

void input_UpdateMouseVariables(int disengageTrigger) {
    input_RMX = GetMouseX();
    input_RMY = GetMouseY();
    if 
    (
        !disengageTrigger
        ||
        (
            btwn(input_RMX, 0, Global_ResX) 
            &&
            btwn(input_RMY, 0, Global_ResY)
        )
    )
    {
	    input_MX = input_RMX;
	    input_MY = input_RMY;
    }
	input_MD  = IsMouseButtonDown(0);
	input_MRD = IsMouseButtonDown(1);
}

VectorInt2 input_GetMXY() {
	return (VectorInt2){input_MX, input_MY};
}

void input_DrawCursor() {
	DrawRectangle
    (
        input_RMX,
        input_RMY,
        4,
        4,
        GREEN
    );
}
