#pragma once
#include <windows.h>
#include "mathbindings.h"

#define TimeStamp LARGE_INTEGER;

static real invertedFrequency = 0.0f;

LARGE_INTEGER UpdateTimeStamp();
real GetDeltaTime(LARGE_INTEGER *timeStamp);