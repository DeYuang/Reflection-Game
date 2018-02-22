#pragma once
#include "mathbindings.h"
#include "gl/gl.h"

#define RenderingContext HGLRC
#define PixelFormatDescriptor PIXELFORMATDESCRIPTOR
#define DisplayEnvironmentMode DEVMODE
#define Projection GL_PROJECTION
#define ModelView GL_MODELVIEW

const enum BufferMode : uint8 {
	unbuffered = 0, doubleBuffering, trippleBuffering
};

typedef struct Resolution {

	uint16 width;
	uint16 height;
} Resolution;

void GLInit();
void GLUpdate();
void GLSetupViewport(const Resolution resolution, const real fieldOfView, const real nearClip, const real farClip);
void GlTest();

static RenderingContext renderingContext;
static Resolution screenResolution = { 800, 600 };
static bool fullscreen = false;
static bool vSync = false;
static BufferMode bufferMode = BufferMode::doubleBuffering;
static real fieldOfView = 90.0f;
static real nearClip = 1.0f;
static real farClip = 500.0f;

inline bool WaitForVSync(void) {

	if (vSync)
		return false;
	return false;
}

inline bool DoubleBufferingEnabled(void) {

	return (bufferMode == BufferMode::doubleBuffering);
}

inline void ClearScreen(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 255.0f, 0.0f);
}