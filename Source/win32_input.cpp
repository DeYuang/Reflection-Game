#include "win32_input.h"

InputState* UpdateAllInput(InputState *oldState) {

	oldState->keyboardState = *PollKeyboard(&oldState->keyboardState);
	oldState->controllerState = *PollControllers(&oldState->controllerState);
	return oldState;
}

KeyboardState* PollKeyboard(KeyboardState *oldState) {

	return oldState;
}

ControllerState* PollControllers(ControllerState *oldState) {

	return oldState;
}