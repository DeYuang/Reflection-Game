#include <nds.h>
#include "mathbindings.h"
#include "nds_timer.h"

real GetDeltaTime(TimeStamp *timeStamp) {

	TimeStamp oldTime = *timeStamp; 
	*timeStamp = GetCurrentTimestamp();
	return div_int_int((*timeStamp-oldTime), BUS_CLOCK);
}