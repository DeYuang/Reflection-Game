#include "main.h"
#include "mathbindings.h"

static enum BeatMode beatMode = (BeatMode)3;

void SingleHeartbeat( void ) {

	cpuFrameCount++;
	// TODO: Poll keyboard
	// TODO: HB Delta Time
}

void Heartbeat ( void ) {

	uint8 heartbeats = 3;// (uint8)beatMode;
	while (heartbeats --> 0)
		Heartbeat();
}

void Update( void ) {

	frameCount++;
	// TODO: Poll keyboard
	// TODO: Update Delta Time
	//LARGE_INTEGER LastCounter;
	//QueryPerformanceCounter(&LastCounter);

}