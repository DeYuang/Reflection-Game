#include <windows.h>
#include <wingdi.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "win32_main.h"
#include "win32_window.h"
#include "renderer.h"

void _fastcall GLInit( void ) {

	PixelFormatDescriptor pixelFormatDescriptor = {};

	DWORD flags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
	if (bufferMode == BufferMode::doubleBuffering)
		flags = flags | PFD_DOUBLEBUFFER;

	pixelFormatDescriptor.nSize = sizeof(PixelFormatDescriptor);
	pixelFormatDescriptor.nVersion = 1;
	pixelFormatDescriptor.dwFlags = flags;
	pixelFormatDescriptor.iPixelType = PFD_TYPE_RGBA;
	pixelFormatDescriptor.cColorBits = 32;
	pixelFormatDescriptor.cDepthBits = 32;
	pixelFormatDescriptor.iLayerType = PFD_MAIN_PLANE;

	int32 pixelFormat = ChoosePixelFormat(deviceContext, &pixelFormatDescriptor);
	SetPixelFormat(deviceContext, pixelFormat, &pixelFormatDescriptor);

	renderingContext = wglCreateContext(deviceContext);	
	wglMakeCurrent(deviceContext, renderingContext);

	if (fullscreen)
		SwitchToFullscreen();

	GLSetupViewport(screenResolution, 90.0f, 1.0f, 500.0f);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void _fastcall GLUpdate( void ) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 255.0, 0.0);

	glMatrixMode(ModelView);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -5.0f);

	glColor3f(0.7f, 1.0f, 0.3f);

	glBegin(GL_TRIANGLES);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 1.0f);
	glEnd();

	glFlush();

	if (bufferMode == BufferMode::doubleBuffering)
		SwapBuffers(deviceContext);
}

void _fastcall GLSetupViewport(const Resolution resolution, const float fieldOfView, const float nearClip, const float farClip) {

	// ROBUSTNESS: do some checks while in debug

	glViewport(0, 0, resolution.width, resolution.height);
	glMatrixMode(Projection);
	glLoadIdentity();
	gluPerspective(fieldOfView, (GLreal64)resolution.width / (GLreal64)resolution.height, nearClip, farClip);
}