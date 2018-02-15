#pragma once

#define RenderingContext HGLRC
#define PixelFormatDescriptor PIXELFORMATDESCRIPTOR

#define GLreal GLfloat

static RenderingContext renderingContext;

inline bool WaitForVSync( void ) {

	return false;
}

void GLInit();
void GLUpdate();