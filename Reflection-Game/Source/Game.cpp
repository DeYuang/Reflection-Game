#include "main.h"
#include "mathbindings.h"
#include "game.h"

void Heartbeat( void ) {

	cpuFrameCount++;
	// TODO: Poll keyboard
	// TODO: HB Delta Time
}

void HeartbeatLoop ( void ) {

	uint8 heartbeats = (uint8)beatMode;
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