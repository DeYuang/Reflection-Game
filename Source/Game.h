#pragma once
#include "mathbindings.h"
#include "win32_input.h"

const enum BeatMode : uint8 {
	undefined = 0, singleBeat, doubleBeat, tripleBeat, quadrupleBeat,
	pentupleBeat, sextupleBeat, septupleBeat, octupleBeat, nontupleBeat,
	decupleBeat
};

static enum BeatMode beatMode = BeatMode::tripleBeat;

InputState heartbeatInputState;
InputState updateInputState;

void SingleHeartbeat();
void Heartbeat();
void Update();