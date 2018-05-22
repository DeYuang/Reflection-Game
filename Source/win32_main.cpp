#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN
#define NOKANJI
#define NOCRYPT
#define NOGDI

#include <windows.h>

#include "mathbindings.h"
#include "win32.h"
#include "win32_window.h"
#include "main.h"
#include "renderer.h"
#include "game.h"
#include "logging.h"

LRESULT CALLBACK MainWindowProcecure(WindowHandle window, uint32 message,
	WPARAM wideParameter, LPARAM longParameter) {

	switch (message) {

		case WM_QUIT: case WM_CLOSE: case WM_DESTROY: {

			gameIsRunning = false;
		} return 0;

		case WM_SIZE: case WM_SIZING: {

			//uint16 sizeX = (uint16)longParameter;
			//uint16 sizeY = *(uint16*)(&longParameter-1);

			//screenResolution = { sizeX, sizeY };

			GLSetupViewport(screenResolution, fieldOfView, nearClip, farClip);
			GLUpdate();
		} return 0;

		case WM_PAINT: {

			/*Rectangle *clientRectangle = {};
			GetClientRect(window, clientRectangle);

			PaintStruct *paintStruct = (PaintStruct*)malloc(sizeof(PaintStruct));
			DeviceContext paintDeviceContext = BeginPaint(window, paintStruct);
			const uint32 flags = DT_CENTER | DT_VCENTER | DT_SINGLELINE;
			DrawTextA(paintDeviceContext, (LPCSTR)"Hello World!", -1, clientRectangle, flags);
			EndPaint(window, paintStruct);*/

			GLUpdate();
		}

		default:
			return DefWindowProc(window, message, wideParameter, longParameter);
	}
	return DefWindowProc(window, message, wideParameter, longParameter);
}

int WINAPI WinMain(const InstanceHandle instance,
		const InstanceHandle previous,
		const LPSTR arguments,
		const int32 code) {

	// Window and engine init
	instanceHandle = instance;
	WindowClass windowClass = CreateWindowClass(gameNameClass, MainWindowProcecure);

	if (RegisterClassA(&windowClass)) {
		WindowHandle gameWindow = OpenNewWindow(gameNameClass, (LPCSTR)gameName, &screenResolution);

		deviceContext = GetDC(gameWindow);

		GLInit();
		LogConsole("Engine Initialized!\r\n");

		// Message que and game loop
		while (gameIsRunning) {
			Message message;
			while (PeekMessage(&message, 0, 0, 0, PM_REMOVE)) {
				if (message.message == WM_QUIT || message.message == WM_CLOSE || message.message == WM_DESTROY)
					return 0;

				DispatchMessage(&message);
			}

			Heartbeat();
			Update();

			while (WaitForVSync())
				SingleHeartbeat();

			GLUpdate();
		}
	}
	
	return 0;
}