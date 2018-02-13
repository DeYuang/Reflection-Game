#pragma once
#include <windows.h>

static char* gameName = "Reflection Game";
static LPCSTR gameNameClass = (LPCSTR)"Reflection Game Class";

static bool isRunning = true;
static HDC	deviceContext;
static HINSTANCE instanceHandle;

static int cpuFrameCount;
static int frameCount;