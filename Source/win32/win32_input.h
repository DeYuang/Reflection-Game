#pragma once
#include "mathbindings.h"

#define KeyboardState int32
#define MouseState int32
#define ControllerState int32

typedef struct InputState {

	KeyboardState keyboardState;
	MouseState mouseState;
	ControllerState controllerState;
} InputState;

InputState* UpdateAllInput(InputState *oldState);
KeyboardState* PollKeyboard(KeyboardState *oldState);
MouseState* PollMouse(MouseState *oldState);
ControllerState* PollControllers(ControllerState *oldState);