#pragma once
#include "mathbindings.h"

#define TimeStamp _LARGE_INTEGER;

static real invertedFrequency = 0.0f;

//TimeStamp UpdateTimeStamp();
real GetDeltaTime(_LARGE_INTEGER *timeStamp);