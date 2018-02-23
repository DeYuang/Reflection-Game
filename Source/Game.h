#pragma once
#include "mathbindings.h"
#include "nds_timer.h"
#include "nds_input.h"

enum BeatMode : uint8 {
	undefined = 0, singleBeat, doubleBeat, tripleBeat, quadrupleBeat,
	pentupleBeat, sextupleBeat, septupleBeat, octupleBeat, nontupleBeat,
	decupleBeat
};

static enum BeatMode beatMode = BeatMode::tripleBeat;

static InputState *heartbeatInputState;
static InputState *updateInputState;

static TimeStamp *heartbeatTimeStamp;
static TimeStamp *updateTimeStamp;

void Update();
void SingleHeartbeat();
void Heartbeat();