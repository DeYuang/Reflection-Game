#pragma once
#include "mathbindings.h"

#define Projection GL_PROJECTION
#define ModelView GL_MODELVIEW

#define GLreal GLfloat
#define GLreal64 GLdouble
#define RenderingContext HGLRC
#define PixelFormatDescriptor PIXELFORMATDESCRIPTOR
#define DisplayEnvironmentMode DEVMODE

const enum BufferMode : uint8 {
	unbuffered = 0, doubleBuffering, trippleBuffering
};

typedef struct Resolution {

	uint16 width;
	uint16 height;
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

void _fastcall GLInit();
void _fastcall GLUpdate();
void _fastcall GLSetupViewport(const Resolution resolution, const float fieldOfView, const float nearClip, const float farClip);