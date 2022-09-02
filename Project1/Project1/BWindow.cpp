#include "BWindow.h"

BWindow::BWindow() :m_hWnd(nullptr), m_hInstance(nullptr)
{
	// Do Not
}

BWindow::~BWindow()
{
	// DO Not
}

int BWindow::Run(HINSTANCE hInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	// Start
	m_hInstance = hInstance;
	this->RegisterWndClass();
	this->WindowCreate();
	this->WindowShow(nCmdShow);

	return this->MessageLoop();
}

LRESULT BWindow::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		break;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

void BWindow::RegisterWndClass()
{
	WNDCLASSEX winClassEx;
	winClassEx.cbSize = sizeof(LPWNDCLASSEX);
	winClassEx.style = CS_HREDRAW | CS_VREDRAW;
	winClassEx.lpfnWndProc = BWindow::WndProc;
	winClassEx.cbClsExtra = 0;
	winClassEx.cbWndExtra = 0;
	winClassEx.hInstance = m_hInstance;
	winClassEx.hIcon = LoadIcon(m_hInstance, IDI_APPLICATION);
	winClassEx.hCursor = LoadCursor(nullptr, IDC_ARROW);
	winClassEx.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	winClassEx.lpszMenuName = nullptr;
	winClassEx.lpszClassName = BASIC_WINDOW_NAME;
	winClassEx.hIconSm = LoadIcon(m_hInstance, IDI_APPLICATION);

	RegisterClassEx(&winClassEx);
}

void BWindow::WindowCreate()
{
	// 클래스 이름, 윈도우 이름, 스타일, x, y, w, h, 부모, 메뉴, 인스턴스, LParam
	m_hWnd = CreateWindow(BASIC_WINDOW_NAME, _T("Framework"), WS_OVERLAPPEDWINDOW, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, nullptr, nullptr, m_hInstance, nullptr);
}

void BWindow::WindowShow(int nCmdShow)
{
	ShowWindow(m_hWnd, nCmdShow);
}

int BWindow::MessageLoop()
{
	MSG msg;
	memset(&msg, 0, sizeof(msg)); 

	this->StartUp(); // 추상 메서드

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			this->MainLoop(); // 따로 메세지 없으면 메인루프
		}
	}

	this->CleanUp(); // 추상 메서드
	return (int)msg.wParam;
}

HWND BWindow::GetWindowHandle()
{
	return m_hWnd;
}

HINSTANCE BWindow::GetInstanceHandle()
{
	return m_hInstance;
}
