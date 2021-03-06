#include "input.h"

InputState* UpdateAllInput(InputState *oldState) {

	oldState->keyboardState = *PollKeyboard(&oldState->keyboardState);
	oldState->mouseState = *PollMouse(&oldState->mouseState);
	oldState->controllerState = *PollControllers(&oldState->controllerState);
	return oldState;
}

KeyboardState* PollKeyboard(KeyboardState *oldState) {

	return oldState;
}

MouseState* PollMouse(MouseState *oldState) {

	return oldState;
}

ControllerState* PollControllers(ControllerState *oldState) {

	return oldState;
}