#pragma once
#include "mathbindings.h"

const enum BeatMode : uint8 {
	undefined = 0, singleBeat, doubleBeat, tripleBeat, quadrupleBeat,
	pentupleBeat, sextupleBeat, septupleBeat, octupleBeat, nontupleBeat,
	decupleBeat
};

void SingleHeartbeat();
void Heartbeat();
void Update();