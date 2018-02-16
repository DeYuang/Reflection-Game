#pragma once
#include "mathbindings.h"

#define GLreal GLfloat
#define RenderingContext HGLRC
#define PixelFormatDescriptor PIXELFORMATDESCRIPTOR
#define DisplayEnvironmentMode DEVMODE

const enum BufferMode : uint8 {
	unbuffered = 0, doubleBuffering, trippleBuffering
};

typedef struct Resolution {

	int16 width;
	int16 height;
} Resolution;

static RenderingContext renderingContext;

// --[Default Render Settings]--
static Resolution screenResolution = { 800, 600 };
static bool fullscreen = false;
static bool vSync = false;
static BufferMode bufferMode = BufferMode::doubleBuffering;

inline bool WaitForVSync( void ) {

	if(vSync)
		return false;
	return false;
}

void GLInit();
void GLUpdate();