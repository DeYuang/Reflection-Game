#include "mathbindings.h"
#include "main.h"
#include "timer.h"
#include "input.h"
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

void Heartbeat( void ) {

	uint8 heartbeats = (uint8)beatMode;
	while (heartbeats--> 0)
		SingleHeartbeat();
}