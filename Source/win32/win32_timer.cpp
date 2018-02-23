#include <windows.h>

#include "mathbindings.h"
#include "win32_timer.h"

/*TimeStamp UpdateTimeStamp( void ) {

	return 0;
}*/

real GetDeltaTime(_LARGE_INTEGER *timeStamp) {

	uint64 oldTimeStamp = timeStamp->QuadPart;
	QueryPerformanceCounter(timeStamp);
	uint64 newTimeStamp = timeStamp->QuadPart;

	//if (oldTimeStamp > newTimeStamp)
	//	return (real)(((uint64)newTimeStamp + uint32max) - oldTimeStamp) * invertedFrequency;

	return (real)(newTimeStamp - oldTimeStamp) * invertedFrequency;
}