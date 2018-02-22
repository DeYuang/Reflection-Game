#include <windows.h>
#include <wingdi.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "win32_main.h"
#include "win32_window.h"
#include "renderer.h"

void GLInit( void ) {

	PixelFormatDescriptor* pixelFormatDescriptor = CreatePixelFormatDescriptor(DoubleBufferingEnabled());

	int32 pixelFormat = ChoosePixelFormat(deviceContext, pixelFormatDescriptor);
	SetPixelFormat(deviceContext, pixelFormat, pixelFormatDescriptor);

	CreateRenderingContext();
	GLSetupViewport(screenResolution, fieldOfView, nearClip, farClip);

	if (fullscreen)
		SwitchToFullscreen();
}

void GLUpdate( void ) {

	ClearScreen();

	GlTest();

	if (DoubleBufferingEnabled())
		SwapBuffers(deviceContext);
}

void GLSetupViewport(const Resolution resolution, const real fieldOfView, const real nearClip, const real farClip) {

	// ROBUSTNESS: do some checks while in debug

	glMatrixMode(Projection);
	glLoadIdentity();
	gluPerspective(fieldOfView, (real64)resolution.width / (real64)resolution.height, nearClip, farClip);

	glViewport(0, 0, resolution.width, resolution.height);
	ClearScreen();
}

void GlTest( void ) {

	glMatrixMode(ModelView);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -5.0f);

	glBegin(GL_TRIANGLES);
	glColor3f(0.7f, 1.0f, 0.3f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 1.0f);
	glEnd();

	glFlush();
}