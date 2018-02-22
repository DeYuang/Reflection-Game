#include "win32_main.h"
#include "win32_input.h"
#include "win32_timer.h"
#include "mathbindings.h"
#include "game.h"

void Update( void ) {

	frameCount++;
	updateInputState = UpdateAllInput(updateInputState);
	real deltaTime = GetDeltaTime(heartbeatTimeStamp);
}

void SingleHeartbeat(void) {

	heartbeatCount++;
	heartbeatInputState = UpdateAllInput(heartbeatInputState);
	real deltaTime = GetDeltaTime(updateTimeStamp);
}

void InitEngine(void) {

	heartbeatInputState = {};
	updateInputState = {};

	LARGE_INTEGER *CPUFrequency;
	QueryPerformanceFrequency(CPUFrequency);
	invertedFrequency = 1.0f / CPUFrequency->QuadPart;
}

void Heartbeat( void ) {

	uint8 heartbeats = (uint8)beatMode;
	while (heartbeats--> 0)
		SingleHeartbeat();
}