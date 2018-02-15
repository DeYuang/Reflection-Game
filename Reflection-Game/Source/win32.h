#pragma once
#include <windows.h>

#define InstanceHandle HINSTANCE
#define WindowClass WNDCLASSA
#define WindowHandle HWND
#define DeviceContext HDC
#define Message MSG
#define WindowsProcedure WNDPROC

WindowClass CreateWindowClass(const LPCSTR windowTitle, const WindowsProcedure windowProcedure);
WindowHandle OpenNewWindow(const LPCSTR windowClass, const LPSTR windowTitle);