#include <windows.h>

#include "main.h"
#include "renderer.h"

WindowClass CreateWindowClass(const LPCSTR windowClassName, const WindowsProcedure windowProcedure) {

	WindowClass windowClass = {};
	windowClass.hInstance = instanceHandle;
	windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	windowClass.lpfnWndProc = windowProcedure;
	windowClass.lpszClassName = windowClassName;

	return windowClass;
}

WindowHandle OpenNewWindow(const LPCSTR windowClass, const LPCSTR windowTitle, const Resolution* windowSize) {

	return CreateWindowExA(0,
		windowClass, windowTitle,
		WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_POPUP | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
		CW_USEDEFAULT, CW_USEDEFAULT,
		windowSize->width, windowSize->height,
		NULL, NULL, instanceHandle, NULL);
}