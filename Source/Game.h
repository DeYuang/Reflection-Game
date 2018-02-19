#pragma once
#include "mathbindings.h"

const enum BeatMode : uint8 {
	undefined = 0, singleBeat, doubleBeat, tripleBeat, quadrupleBeat,
	pentupleBeat, sextupleBeat, septupleBeat, octupleBeat, nontupleBeat,
	decupleBeat
};

static enum BeatMode beatMode = BeatMode::tripleBeat;

void SingleHeartbeat();
void Heartbeat();
void Update();