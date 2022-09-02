#ifndef BWINDOW_H
#define BWINDOW_H

#include "BBasicStd.h"

class BWindow
{
public:
    BWindow(); //������
    ~BWindow(); //�ı���

public:
    int Run(HINSTANCE hInstance, LPWSTR lpCmdLine, int nCmdShow);
    static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

    //�̰� BWindow�� ���� ������� �ϵ�
private:
    void RegisterWndClass();
    void WindowCreate();
    void WindowShow(int nCmdShow);
    int MessageLoop();

    //�̰� Bwindow�� ��ӹ��� �༮���� �����ؾ��ϴ� �͵�
public:
    virtual void StartUp() = 0;  //�߻� �ż��� ������
    virtual void MainLoop() = 0;
    virtual void CleanUp() = 0;

protected:
    HWND m_hWnd;
    HINSTANCE m_hInstance; //��������� ������ �ڵ�� �ν��Ͻ� �ڵ��� ������ �־�� �Ѵ�.

public:
    HWND GetWindowHandle(); //������� ����
    HINSTANCE GetInstanceHandle();
};

#endif // !BWINDOW_H