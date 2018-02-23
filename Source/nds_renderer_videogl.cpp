#include <nds.h>
#include "nds_renderer_videogl.h"

void GLInit( void ){

	consoleDemoInit();
	glInit();
	
	// Set mode 0, enable BG0 and set it to 3D
	videoSetMode(MODE_0_3D);
	
	// Setup the rear plane
	glClearColor(0, 0, 0, 255); 	// BG must be opaque for AA to work
	glClearPolyID(63); 				// BG must have a unique polygon ID for AA to work
	glClearDepth(0x7FFF);
	
	glEnable(GL_ANTIALIAS);
	glDisable(GL_FOG);
	
	ClearScreen();
}

void GLUpdate( void ){

}

void GLSetupViewport(const Resolution resolution, const real fieldOfView, const real nearClip, const real farClip){

	glMatrixMode(Projection);
	glLoadIdentity();
	gluPerspectivef32(fieldOfView, (real64)resolution.width / (real64)resolution.height, nearClip, farClip);

	glViewport(0, 0, resolution.width, resolution.height);
	ClearScreen();
}

void GlTest( void ){

}