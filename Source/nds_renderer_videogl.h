#include <nds.h>

#define Projection GL_PROJECTION
#define ModelView GL_MODELVIEW

typedef struct Resolution {

	uint16 width;
	uint16 height;
} Resolution;

void GLInit();
void GLUpdate();
void GLSetupViewport(const Resolution resolution, const real fieldOfView, const real nearClip, const real farClip);
void GlTest();

static Resolution screenResolution = { 255, 191 };
static real fieldOfView = 90.0f;
static real nearClip = 1.0f;
static real farClip = 500.0f;

inline void ClearScreen(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}