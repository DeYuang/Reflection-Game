#include <windows.h>


#include "win32.h"
#include "main.h"
#include "renderer.h"
#include "game.h"
#include "logging.h"

LRESULT CALLBACK MainWindowProcecure(HWND window, UINT message,
	WPARAM wideParameter, LPARAM longParameter) {

	switch (message) {

		case WM_PAINT: {

			PAINTSTRUCT paint;
			HDC deviceContext = BeginPaint(window, &paint);
			RECT rect;
			GetClientRect(window, &rect);
			UINT flags = DT_CENTER | DT_VCENTER | DT_SINGLELINE;
			DrawText(deviceContext, (LPCWSTR)"Hello World!", -1, &rect, flags);
			EndPaint(window, &paint);

		} break;

		default:
			return DefWindowProc(window, message, wideParameter, longParameter);
	}

	return 0;
}

int WINAPI WinMain(HINSTANCE instance,
		HINSTANCE previous,
		LPSTR arguments,
		int code) {

	// Window and engine init
	instanceHandle = instance;
	WNDCLASSA windowClass = CreateWindowClass(gameName, MainWindowProcecure);

	if (RegisterClassA(&windowClass)) {
		HWND gameWindow =
			CreateWindowExA(0,
				windowClass.lpszClassName, (LPSTR)gameName,
				WS_OVERLAPPEDWINDOW | WS_VISIBLE,
				CW_USEDEFAULT, CW_USEDEFAULT,
				CW_USEDEFAULT, CW_USEDEFAULT,
				NULL, NULL, instance, NULL);

		deviceContext = GetDC(gameWindow);
		LogMessageBox("Engine initalized!");

		// Message que and game loop
		while (isRunning) {
			MSG message;
			while (PeekMessage(&message, 0, 0, 0, PM_REMOVE)) {
				if (message.message == WM_QUIT || message.message == WM_CLOSE) {
					isRunning = false;
					return 0;
				}

				TranslateMessage(&message);
				DispatchMessage(&message);
			}

			HeartbeatLoop();
			Update();

			while (WaitForVSync())
				Heartbeat();

			GLUpdate();
		}
	}

	return 0;
}

