#include "win32_main.h"
#include "win32_input.h"
#include "mathbindings.h"
#include "game.h"

void SingleHeartbeat( void ) {

	heartbeatCount++;
	heartbeatInputState = *UpdateAllInput(&heartbeatInputState);
	// TODO: HB Delta Time
}

void Update(void) {

	frameCount++;
	updateInputState = *UpdateAllInput(&updateInputState);
	// TODO: Update Delta Time
	//LARGE_INTEGER LastCounter;
	//QueryPerformanceCounter(&LastCounter);
}

void Heartbeat(void) {

	uint8 heartbeats = (uint8)beatMode;
	while (heartbeats--> 0)
		SingleHeartbeat();
}