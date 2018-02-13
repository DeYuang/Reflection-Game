#pragma once
enum BeatMode : int {
	undefined = 0, singleBeat, doubleBeat, tripleBeat, quadrupleBeat,
	pentupleBeat, sextupleBeat, septupleBeat, octupleBeat, nontupleBeat,
	decupleBeat
};

enum BeatMode beatMode = tripleBeat;

void Heartbeat();
void Update();