#pragma once
#include <windows.h>
#include "win32.h"
#include "mathbindings.h"

static const char* gameName = "Reflection Game";
static const LPSTR gameNameClass = (LPSTR)"Reflection Game Class";

static DeviceContext deviceContext;
static InstanceHandle instanceHandle;

static bool gameIsRunning = true;
static int heartbeatCount;
static int frameCount;

LRESULT CALLBACK MainWindowProcecure(WindowHandle window, uint32 message,
	WPARAM wideParameter, LPARAM longParameter);
int WINAPI WinMain(const InstanceHandle instance,
	const InstanceHandle previous,
	const LPSTR arguments,
	const int32 code);