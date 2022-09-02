#include "BWindow.h"

BWindow::BWindow() :m_hWnd(nullptr), m_hInstance(nullptr)
{
	//do nothing
}

BWindow::~BWindow()
{
	//do nothing
}

//�����츦 ����ְ�, �����Ѵ����� ���ѷ����� ���� ������ ���ִ� �Լ�
int BWindow::Run(HINSTANCE hInstance, LPWSTR lpCmdLine, int nCmdShow)
{
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
	}
	return DefWindowProcW(hwnd, message, wParam, lParam);
}

void BWindow::RegisterWndClass()
{
	WNDCLASSEX winClassEx;
	winClassEx.cbSize = sizeof(WNDCLASSEX);
	winClassEx.style = CS_HREDRAW | CS_VREDRAW;
	winClassEx.lpfnWndProc = BWindow::WndProc; //�޽��� �ڵ� ���ν��� ���
	winClassEx.cbClsExtra = 0;
	winClassEx.cbWndExtra = 0;
	winClassEx.hInstance = m_hInstance;
	winClassEx.hIcon = LoadIcon(m_hInstance, IDI_APPLICATION);
	winClassEx.hCursor = LoadCursor(nullptr, IDC_ARROW);
	winClassEx.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); //�̰� �Ƹ� ȸ���ϲ���
	winClassEx.lpszMenuName = nullptr;
	winClassEx.lpszClassName = BASIC_WINDOW_NAME;
	winClassEx.hIconSm = LoadIcon(m_hInstance, IDI_APPLICATION);

	RegisterClassEx(&winClassEx);
}

void BWindow::WindowCreate()
{
	//Ŭ���� �̸�, ������ �̸�, ��Ÿ��, x, y, w, h, �θ�, �޴�, �ν��Ͻ�, lparam
	m_hWnd = CreateWindow(
		BASIC_WINDOW_NAME, _T("FrameWork"), WS_OVERLAPPEDWINDOW,
		0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, nullptr, nullptr, m_hInstance, nullptr);

}

void BWindow::WindowShow(int nCmdShow)
{
	ShowWindow(m_hWnd, nCmdShow);
}

int BWindow::MessageLoop()
{
	MSG msg;
	memset(&msg, 0, sizeof(msg)); //���� 0���� Ŭ���ϰ� �����

	this->StartUp(); //�߻�ż��� : �ڽ��� �����Ҳ���

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			this->MainLoop(); //������ �޽����� ���� ��� ���η��� ����
		}
	}

	this->CleanUp(); //�߻�ż���: �ڽ��� �����ؼ� �ڱⰡ ����� ġ�ﲨ��
	return (int)msg.wParam; //�����ڵ带 �������ָ� �ȴ�.
}

HWND BWindow::GetWindowHandle()
{
	return m_hWnd;
}

HINSTANCE BWindow::GetInstanceHandle()
{
	return m_hInstance;
}