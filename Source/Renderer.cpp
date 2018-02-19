#include <windows.h>
#include <wingdi.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "win32_main.h"
#include "renderer.h"

void GLInit( void ) {

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

	if (fullscreen) {
		DisplayEnvironmentMode displayEnvironment = {};
		displayEnvironment.dmSize = sizeof(DisplayEnvironmentMode);
		displayEnvironment.dmBitsPerPel = 32;
		displayEnvironment.dmPelsHeight = screenResolution.height;
		displayEnvironment.dmPelsWidth = screenResolution.width;
		displayEnvironment.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | DM_BITSPERPEL;
		LONG value = ChangeDisplaySettings(&displayEnvironment, CDS_FULLSCREEN);

		ShowCursor(false);
	}

	glViewport(0, 0, screenResolution.width, screenResolution.height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(52.0f, screenResolution.width/screenResolution.height, 1.0f, 1000.0f);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	
}

void GLUpdate( void ) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 255.0, 0.0);

	glMatrixMode(GL_MODELVIEW);
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