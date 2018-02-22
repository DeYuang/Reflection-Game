#pragma once
#include "mathbindings.h"
#include "win32_timer.h"
#include "win32_input.h"

const enum BeatMode : uint8 {
	undefined = 0, singleBeat, doubleBeat, tripleBeat, quadrupleBeat,
	pentupleBeat, sextupleBeat, septupleBeat, octupleBeat, nontupleBeat,
	decupleBeat
};

static enum BeatMode beatMode = BeatMode::tripleBeat;

static InputState *heartbeatInputState;
static InputState *updateInputState;

static LARGE_INTEGER *heartbeatTimeStamp;
static LARGE_INTEGER *updateTimeStamp;

void Update();
void SingleHeartbeat();
void InitEngine();
void Heartbeat();