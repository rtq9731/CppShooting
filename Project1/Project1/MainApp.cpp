#include "MainApp.h"

MainApp::MainApp()
{
}

MainApp::~MainApp()
{
}

void MainApp::Init()
{
	//�� �ʱ�ȭ�� �־�� �ϴµ� ���� ����.
}

void MainApp::Update(float deltaTime)
{
}

void MainApp::Render(HDC hdc, float deltaTime)
{
}

void MainApp::Release()
{
}


int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	shared_ptr<MainApp> app = make_shared<MainApp>(); //�����ϳ� ����
	app->Run(hInstance, lpCmdLine, nCmdShow);

	return 0;
}