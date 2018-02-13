#include <windows.h>

#include "game.h"

static bool isRunning = true;

LRESULT CALLBACK WinProc(HWND window, UINT message,
	WPARAM wideParameter, LPARAM longParameter) {

	switch (message) {

		case WM_CLOSE:	{
			isRunning = false;
		} break;

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
	WNDCLASS windowClass= {};
	windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	windowClass.lpfnWndProc = WinProc;
	windowClass.hInstance = instance;
	windowClass.lpszClassName = (LPCWSTR)"Reflection Game";
	if (RegisterClass(&windowClass)) {
		HWND gameWindow =
			CreateWindowEx(0,
				windowClass.lpszClassName, (LPWSTR)"Reflection Game",
				WS_OVERLAPPEDWINDOW | WS_VISIBLE,
				CW_USEDEFAULT, CW_USEDEFAULT,
				CW_USEDEFAULT, CW_USEDEFAULT,
				NULL, NULL, instance, NULL);

		// Message que and game loop
		while (isRunning) {
			MSG message;
			while (PeekMessage(&message, 0, 0, 0, PM_REMOVE)) {
				if (message.message == WM_QUIT) {
					isRunning = false;
					break;
				}

				TranslateMessage(&message);
				DispatchMessage(&message);
			}

			// TODO: Poll keyboard
			// TODO: HB Delta Time
			Heartbeat();
			// TODO: Update Delta Time
			Update();
		}
	}

	return 0;
}

