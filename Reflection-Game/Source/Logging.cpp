#include <windows.h>

#include "main.h"

void LogConsole(char* message) {

}

void LogMessageBox(char* message) {

	MessageBoxA(0, message, gameName, MB_OK | MB_ICONINFORMATION);
}