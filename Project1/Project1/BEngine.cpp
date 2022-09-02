#include "BEngine.h"

shared_ptr<BEngine> g_sEngine = nullptr; //���������� ������ ������ �� �ְ� ���� �����ΰ�

BEngine::BEngine() :
	m_llPrevCount{}, m_llCurCount{}, m_llFrequency{},
	m_fDT(0.0f), m_fAcc(0.f), m_iCallCount(0), m_iFPS(0)
{
	//���߿� ���⿡ ���Ŵ��� ���� ������ �ҰŴ�.

	//���� CPU�� ī��Ʈ ƽ�� �޾ƿ´�.
	QueryPerformanceCounter(&m_llPrevCount);

	//���� ���� ī������ Ÿ�̸� ���ļ���ȯ : �ʴ� ī��Ʈ ���� ��ȯ�Ѵ�.
	QueryPerformanceFrequency(&m_llFrequency);
}

BEngine::~BEngine()
{
}

void BEngine::StartUp()
{
	g_sEngine = shared_from_this(); //���������� �ڱ��ڽ��� ���� �Ҵ����ְ�
	Init(); //�ۿ��� �ʱ�ȭ�� �۾��� �ִٸ� �����ؼ� �ʱ�ȭ�Ѵ�.

	//�� �Լ��� �� �ѹ��� ����ȴ�.

}

void BEngine::MainLoop()
{
	QueryPerformanceCounter(&m_llCurCount);

	m_fDT = (float)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / (float)m_llFrequency.QuadPart;

	m_llPrevCount = m_llCurCount; //ī��Ʈ ����

	++m_iCallCount;
	m_fAcc += m_fDT;//�����ð� �ջ�
	if (m_fAcc >= 1.0f)
	{
		m_iFPS = m_iCallCount;
		m_fAcc = 0;
		m_iCallCount = 0;

		RenderText(m_iFPS, m_fDT); //������ ĸ��â�� ��ﲨ��
	}

	_Update(m_fDT);

	HDC hdc = GetDC(m_hWnd); //������ �ڵ�κ��� DC�� ���ٰ�
	_Render(hdc, m_fDT); //ȭ�� �׸��� ����

	ReleaseDC(m_hWnd, hdc); //�� ������ ��ȯ
}

void BEngine::CleanUp()
{
	this->Release();

	//�Է�, ����, �� ���� ������ ����� �Ѵ�.
}

void BEngine::_Update(float deltaTime)
{
	//�Է� ������Ʈ 
	//���� ������Ʈ

	Update(deltaTime);
}

void BEngine::_Render(HDC hdc, float deltaTime)
{
	HDC hMemDC;
	RECT winRect;
	HBITMAP bitmap;

	GetClientRect(this->GetWindowHandle(), &winRect); //���� ������ �ڵ��� ���ؼ� �������� ũ�⸦ ��Ȯ�ϰ� �˾Ƴ���

	hMemDC = CreateCompatibleDC(hdc); //���� HDC�� ȣȯ�Ǵ� �޸� DC�� �ϳ� �����Ѵ�.

	bitmap = CreateCompatibleBitmap(hdc, winRect.right, winRect.bottom); //ȣȯ ��Ʈ�� ������
	SelectObject(hMemDC, bitmap);
	FillRect(hMemDC, &winRect, (HBRUSH)COLOR_BACKGROUND); //ȸ������ �簢�� �׷��ְ�

	Render(hMemDC, deltaTime); //�ڽ����� �� �޸� DC�� �Ѱ��ش�. �ڽ��� ������ �� �޸� DC�� �׸��� ���뼭 ��� �׸��� �ȴ�.

	//��ӹ��� �༮���� bitmap ��ü�� memDC�� �׸��͵��� ���� �׷ȴٸ� BitBlt�� �̿��ؼ� ���� ȭ�鿡 ����ϵ��� �����ش�.
	BitBlt(hdc, 0, 0, winRect.right, winRect.bottom, hMemDC, 0, 0, SRCCOPY);

	DeleteObject(bitmap);
	DeleteDC(hMemDC);
}

void BEngine::RenderText(UINT fps, float deltaTime)
{
	static TCHAR szTemp[256];
	swprintf_s(szTemp, _T("Game FPS : %d, DT : %f"), fps, deltaTime);
	SetWindowText(m_hWnd, szTemp); //Ÿ��Ʋ�� �� ������ ��µǰ� �ȴ�.
}

void BEngine::Init()
{
}

void BEngine::Update(float deltaTime)
{
}

void BEngine::Render(HDC hdc, float deltaTime)
{
}

void BEngine::Release()
{
}