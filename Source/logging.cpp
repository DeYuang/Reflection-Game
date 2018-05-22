#include <windows.h>

#include "main.h"

void LogConsole(const char* message) {

	OutputDebugStringA(message);
}

void LogMessageBox(const char* message) {

	MessageBoxA(NULL, message, gameName, MB_OK | MB_ICONINFORMATION);
}