#pragma once
#include <windows.h>
#include "win32.h"

static const char* gameName = "Reflection Game";
static const LPSTR gameNameClass = (LPSTR)"Reflection Game Class";

static DeviceContext deviceContext;
static InstanceHandle instanceHandle;

static bool gameIsRunning = true;
static int heartbeatCount;
static int frameCount;