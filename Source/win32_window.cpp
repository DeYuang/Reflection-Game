#include <windows.h>

#include "main.h"
#include "renderer.h"

WindowClass CreateWindowClass(const LPCSTR windowClassName, const WindowsProcedure windowProcedure) {

	WindowClass windowClass = {};
	windowClass.hInstance = instanceHandle;
	windowClass.lpszClassName = windowClassName;
	windowClass.lpfnWndProc = windowProcedure;
	windowClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	//windowClass.hCursor = LoadCursorA(NULL, IDC_ARROW);

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

PixelFormatDescriptor* CreatePixelFormatDescriptor(const bool doubleBuffering) {

	PixelFormatDescriptor pixelFormatDescriptor = *(PixelFormatDescriptor*)malloc(sizeof(PixelFormatDescriptor));

	DWORD flags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
	if (doubleBuffering)
		flags = flags | PFD_DOUBLEBUFFER;

	pixelFormatDescriptor.nSize = sizeof(PixelFormatDescriptor);
	pixelFormatDescriptor.nVersion = 1;
	pixelFormatDescriptor.dwFlags = flags;
	pixelFormatDescriptor.iPixelType = PFD_TYPE_RGBA;
	pixelFormatDescriptor.cColorBits = 32;
	pixelFormatDescriptor.cDepthBits = 32;
	pixelFormatDescriptor.iLayerType = PFD_MAIN_PLANE;

	return &pixelFormatDescriptor;
}

void CreateRenderingContext( void ) {

	renderingContext = wglCreateContext(deviceContext);
	wglMakeCurrent(deviceContext, renderingContext);
}

 void SwitchToFullscreen( void ) {

	 DisplayEnvironmentMode displayEnvironment = {};
	 displayEnvironment.dmSize = sizeof(DisplayEnvironmentMode);
	 displayEnvironment.dmBitsPerPel = 32;
	 displayEnvironment.dmPelsHeight = screenResolution.height;
	 displayEnvironment.dmPelsWidth = screenResolution.width;
	 displayEnvironment.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | DM_BITSPERPEL;

	 ShowCursor(false);
	 ChangeDisplaySettings(&displayEnvironment, CDS_FULLSCREEN);
}