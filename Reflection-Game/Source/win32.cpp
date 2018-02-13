#include <windows.h>

#include "main.h"

WNDCLASSA CreateWindowClass(char* windowTitle, WNDPROC windowProcedure) {

	WNDCLASSA windowClass = {};
	windowClass.hInstance = instanceHandle;
	windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	windowClass.lpfnWndProc = windowProcedure;
	windowClass.lpszClassName = windowTitle;

	return windowClass;
}