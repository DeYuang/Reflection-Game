#pragma once
#include <windows.h>

#include "win32.h"

static const char* gameName = "Reflection Game";
static const LPSTR gameNameClass = (LPSTR)"Reflection Game Class";

static bool gameIsRunning = true;
static DeviceContext deviceContext;
static InstanceHandle instanceHandle;

static int cpuFrameCount;
static int frameCount;