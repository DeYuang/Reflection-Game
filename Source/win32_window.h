#pragma once
#include <windows.h>
#include "renderer.h"

#include "win32.h"

WindowClass CreateWindowClass(const LPCSTR windowTitle, const WindowsProcedure windowProcedure);
WindowHandle OpenNewWindow(const LPCSTR windowClass, const LPCSTR windowTitle, const Resolution* windowSize);
PixelFormatDescriptor* CreatePixelFormatDescriptor(const bool doubleBuffering);
void CreateRenderingContext();
void SwitchToFullscreen();