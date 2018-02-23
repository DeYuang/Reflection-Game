#include <nds.h>
#include "game.h"

void InitEngine(void) {

	heartbeatInputState = {};
	updateInputState = {};
	
	InitTimers();
}

int main(void) {

	InitEngine();
	GLInit();
	LogConsole("Engine Initialized!\r\n");

	while (gameIsRunning) {

		Heartbeat();
		Update();

		while (WaitForVSync())
			SingleHeartbeat();

		GLUpdate();
	}

	return 0;
}