#pragma once
#include <windows.h>
#include "renderer.h"

#define InstanceHandle HINSTANCE
#define WindowClass WNDCLASSA
#define WindowHandle HWND
#define DeviceContext HDC
#define Message MSG
#define WindowsProcedure WNDPROC

WindowClass CreateWindowClass(const LPCSTR windowTitle, const WindowsProcedure windowProcedure);
WindowHandle OpenNewWindow(const LPCSTR windowClass, const LPCSTR windowTitle, const Resolution* windowSize);
PixelFormatDescriptor* CreatePixelFormatDescriptor(const bool doubleBuffering);
void CreateRenderingContext();
void SwitchToFullscreen();