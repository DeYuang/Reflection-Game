#include <windows.h>

#include "win32.h"
#include "main.h"
#include "renderer.h"
#include "game.h"
#include "logging.h"

LRESULT CALLBACK MainWindowProcecure(WindowHandle window, uint32 message,
	WPARAM wideParameter, LPARAM longParameter) {

	switch (message) {

		case WM_QUIT: case WM_CLOSE: {
			gameIsRunning = false;
		} return 0;

		case WM_PAINT: {

			PAINTSTRUCT paint;
			DeviceContext deviceContext = BeginPaint(window, &paint);
			RECT rect;
			GetClientRect(window, &rect);
			uint32 flags = DT_CENTER | DT_VCENTER | DT_SINGLELINE;
			DrawTextA(deviceContext, (LPCSTR)"Hello World!", -1, &rect, flags);
			EndPaint(window, &paint);

		} return 0;

		default:
			return DefWindowProc(window, message, wideParameter, longParameter);
	}

	return 0;
}

int WINAPI WinMain(const InstanceHandle instance,
		const InstanceHandle previous,
		const LPSTR arguments,
		const int32 code) {

	// Window and engine init
	instanceHandle = instance;
	WindowClass windowClass = CreateWindowClass(gameNameClass, MainWindowProcecure);

	if (RegisterClassA(&windowClass)) {
		WindowHandle gameWindow = OpenNewWindow(gameNameClass, (LPSTR)gameName);

		deviceContext = GetDC(gameWindow);
		GLInit();

		LogConsole("Engine Initialized!\r\n");
		//LogMessageBox("Engine initalized!");

		// Message que and game loop
		while (gameIsRunning) {
			Message message;
			while (PeekMessage(&message, 0, 0, 0, PM_REMOVE)) {
				if (message.message == WM_QUIT || message.message == WM_CLOSE)
					return 0;

				TranslateMessage(&message);
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

