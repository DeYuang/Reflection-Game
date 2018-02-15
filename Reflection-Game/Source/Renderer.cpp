#include <windows.h>
#include <Wingdi.h>
#include <GL/gl.h>

#include "main.h"
#include "renderer.h"

void GLInit( void ) {

	PixelFormatDescriptor pixelFormatDescriptor;
	memset(&pixelFormatDescriptor, 0, sizeof(PixelFormatDescriptor));

	pixelFormatDescriptor.nSize = sizeof(PixelFormatDescriptor);
	pixelFormatDescriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pixelFormatDescriptor.nVersion = 1;
	pixelFormatDescriptor.iPixelType = PFD_TYPE_RGBA;
	pixelFormatDescriptor.cColorBits = 32;
	pixelFormatDescriptor.cDepthBits = 24;
	pixelFormatDescriptor.iLayerType = PFD_MAIN_PLANE;

	int pixelFormat = ChoosePixelFormat(deviceContext, &pixelFormatDescriptor);
	SetPixelFormat(deviceContext, pixelFormat, &pixelFormatDescriptor);

	renderingContext = wglCreateContext(deviceContext);
	wglMakeCurrent(deviceContext, renderingContext);

	glMatrixMode(GL_PROJECTION);

	glClear(0);
}

void GLUpdate( void ) {

}