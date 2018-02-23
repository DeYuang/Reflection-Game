#pragma once
#include "mathbindings.h"

#define ControllerState int32
#define StylusState int32

typedef struct InputState {

	ControllerState controllerState;
	StylusState stylusState;
} InputState;

InputState* UpdateAllInput(InputState *oldState);
ControllerState* PollController(ControllerState *oldState);
StylusState* PollStylus(StylusState *oldState);