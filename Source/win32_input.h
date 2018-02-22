#pragma once
#include "mathbindings.h"

#define KeyboardState int32
#define ControllerState int32

typedef struct InputState {

	KeyboardState keyboardState;
	ControllerState controllerState;
} InputState;

InputState* UpdateAllInput(InputState *oldState);
KeyboardState* PollKeyboard(KeyboardState *oldState);
ControllerState* PollControllers(ControllerState *oldState);