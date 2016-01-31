// include windows headers 
#include <Windows.h>
#include <windowsx.h>

// include directx headers
#include <d3d11.h>
#include <d3dx11.h>
#include <D3DX10.h>

// include Direct3D Library files
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dx11.lib")
#pragma comment (lib, "d3dx10.lib")

// global declarations
IDXGISwapChain *swapchain;             // the pointer to the swap chain interface
ID3D11Device *dev;                     // the pointer to our Direct3D device interface
ID3D11DeviceContext *devcon;           // the pointer to our Direct3D device context

									   // function prototypes
void InitD3D(HWND hWnd);     // sets up and initializes Direct3D
void CleanD3D(void);         // closes Direct3D and releases memory


#define null NULL
#define CLASS_NAME "WidnowClass1"
#define WINDOW_TITLE "DirectX 11 App"

							 // WindowProc() prototype
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// the entry point for any Windows program
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	// handler for the window, filled by a function
	HWND hWnd = nullptr;

	// this struct holds information for the window class
	WNDCLASSEX wc = { 0 };

	// clear out the window class for use
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	// fill in the struct with needed information
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = (CS_HREDRAW | CS_VREDRAW);
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(null, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = CLASS_NAME;

	// register the window class               
	RegisterClassEx(&wc);

	RECT wr = { 0, 0, 800, 600 };
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, false);

	// create the window and use the result as the handle
	hWnd = CreateWindowEx(
		null,
		CLASS_NAME,			// name of the window class
		WINDOW_TITLE,		// title of the window
		WS_OVERLAPPEDWINDOW,// window style
		300,	// x-pos 
		300,	// y-pos
		(wr.right - wr.left),	// width
		(wr.bottom - wr.top),	// height
		null,	// paretn window
		null,	// window menus
		hInstance,	// application handle
		null	// user with multiple windows
		);

	// display the window on the screen
	ShowWindow(hWnd, nCmdShow);

	// enter the main loop:

	// this struct holds Windows event messages
	MSG msg;

	// wait for the next message in the queue, store the result in 'msg'
	while (true)
	{
		if (PeekMessage(&msg, null, 0, 0, PM_REMOVE))
		{
			// translate keystroke messages into the right format
			TranslateMessage(&msg);

			//send the message to the WindowsProc()
			DispatchMessage(&msg);

			// check to see if it's time to quit
			if (msg.message == WM_QUIT)
				break;
		}
		else
		{
			// Game Code HERE!
		}

	}

	// return this part of the WM_QUIT message to Windows
	return msg.wParam;
}

// this is the main message handler for the program
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// sort through and find what code to run for the message given
	switch (message)
	{
		// this message is read when the window is closed
	case WM_DESTROY:
	{
		//close the application entirely
		PostQuitMessage(0);
		return 0;
	} break;
	}

	// handle any messages the switch statement didn't
	return DefWindowProc(hWnd, message, wParam, lParam);
}