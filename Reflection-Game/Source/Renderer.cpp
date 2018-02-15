#include <windows.h>
#include <Wingdi.h>
#include <GL/gl.h>

#include "main.h"
#include "renderer.h"

void GLInit( void ) {

	PixelFormatDescriptor pixelFormatDescriptor;
	memset(&pixelFormatDescriptor, 0, sizeof(PixelFormatDescriptor));

	DWORD flags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
	if (bufferMode == BufferMode::doubleBuffering)
		flags = flags | PFD_DOUBLEBUFFER;

	pixelFormatDescriptor.nSize = sizeof(PixelFormatDescriptor);
	pixelFormatDescriptor.nVersion = 1;
	pixelFormatDescriptor.dwFlags = flags;
	pixelFormatDescriptor.iPixelType = PFD_TYPE_RGBA;
	pixelFormatDescriptor.cColorBits = 24;
	pixelFormatDescriptor.cDepthBits = 8;
	pixelFormatDescriptor.iLayerType = PFD_MAIN_PLANE;

	int pixelFormat = ChoosePixelFormat(deviceContext, &pixelFormatDescriptor);
	SetPixelFormat(deviceContext, pixelFormat, &pixelFormatDescriptor);

	renderingContext = wglCreateContext(deviceContext);
	wglMakeCurrent(deviceContext, renderingContext);

	glMatrixMode(GL_PROJECTION);

	glClear(0);
}

void GLUpdate( void ) {

	if (bufferMode == BufferMode::doubleBuffering)
		SwapBuffers(deviceContext);
}