#include <windows.h>

#include "main.h"

WindowClass CreateWindowClass(const char* windowTitle, const WindowsProcedure windowProcedure) {

	WindowClass windowClass = {};
	windowClass.hInstance = instanceHandle;
	windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	windowClass.lpfnWndProc = windowProcedure;
	windowClass.lpszClassName = (LPCSTR)windowTitle;

	return windowClass;
}

WindowHandle OpenNewWindow(const LPCSTR windowClass, const LPSTR windowTitle) {

	return CreateWindowExA(0,
		windowClass, windowTitle,
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, instanceHandle, NULL);
}