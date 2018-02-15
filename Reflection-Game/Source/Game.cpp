#include "main.h"
#include "mathbindings.h"
#include "game.h"
#include "logging.h"

static enum BeatMode beatMode = BeatMode::tripleBeat;

void SingleHeartbeat( void ) {

	cpuFrameCount++;
	// TODO: Poll keyboard
	// TODO: HB Delta Time
}

void Heartbeat ( void ) {

	uint8 heartbeats = (uint8)beatMode;
	while (heartbeats --> 0)
		SingleHeartbeat();
}

void Update( void ) {

	frameCount++;
	// TODO: Poll keyboard
	// TODO: Update Delta Time
	//LARGE_INTEGER LastCounter;
	//QueryPerformanceCounter(&LastCounter);

}