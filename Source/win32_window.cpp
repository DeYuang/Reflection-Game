#include <windows.h>

#include "win32_main.h"
#include "renderer.h"

WindowClass CreateWindowClass(const LPCSTR windowClassName, const WindowsProcedure windowProcedure) {

	WindowClass windowClass = {};
	windowClass.hInstance = instanceHandle;
	windowClass.lpszClassName = windowClassName;
	windowClass.lpfnWndProc = windowProcedure;
	windowClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	windowClass.hCursor = LoadCursorA(NULL, MAKEINTRESOURCEA(IDC_ARROW));

	return windowClass;
}

WindowHandle OpenNewWindow(const LPCSTR windowClass, const LPCSTR windowTitle, const Resolution* windowSize) {

	DWORD windowStyle = WS_VISIBLE | WS_POPUPWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
	if (!fullscreen)
		windowStyle = windowStyle | WS_OVERLAPPEDWINDOW;

	return CreateWindowExA(0,
		windowClass, windowTitle,
		windowStyle,
		CW_USEDEFAULT, CW_USEDEFAULT,
		windowSize->width, windowSize->height,
		NULL, NULL, instanceHandle, NULL);
}