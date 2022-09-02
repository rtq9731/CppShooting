#include "BImage.h"

DWORD BImage::m_TransparentColor = RGB(255, 0, 255);

BImage::BImage() : m_BitmapHandle(nullptr), m_rotateAngle(0)
{
	memset(&m_BitmapInfo, 0, sizeof(m_BitmapInfo));
}

BImage::BImage(const TCHAR* strLoadFile) : BImage();
{
	this->Load(strLoadFile);
}

BImage::~BImage()
{
	if (this->IsEmpty() == false)
	{
		DeleteObject(m_BitmapHandle);
	}
}

bool BImage::Load(const TCHAR* starLoadFile)
{
	/*
	* LoadImage�� �Ķ���ʹ� ������ ����.
	* HINSTANCE, �����̸�, Ÿ��, x, y, �ε� �ɼ�
	* Ÿ�� : IMAGE_BITMAP(0), IMAGE_ICON(1), IMAGE_COURSOR(2)
	* x, y : �̹����� ũ�⸦ ���ϴµ� ���࿡ �� ���� ���� 0�̸鼭 LR_DEFAULTSIZE�� �ɼ����� ����
	*	�ý����� XM_CXICON�� �̿��ؼ� ũ�⸦ �����ϰ� �ǰ�
	*	���� LR_DEFAULT_SIZE�� �����Ǿ� ���� �ʴٸ� ���ҽ��� ���� ũ��� �ε� �ȴ�.
	* 
	* DIB = Device_Independent Bitmap = ��ġ ������ ��Ʈ��, ���� ���� ���̺��� ������ �ִ� ��Ʈ��
	* LR_LOADFROMFILE : ���ҽ� ��� ���� ��θ� �̿��Ͽ� �ҷ��� ��
	* 
	* GetModuleHandle => Moudle�� ���� �ν��Ͻ��ڵ�, dll�̳� exe�� ����ϴµ�,
	* ���⼭�� nullptr�� ������ ���� �ν��Ͻ��� �ڵ��� �Ѿ���� ��.
	*/

	m_BitmapHandle = (HBITMAP)LoadImage(GetModuleHandle(nullptr), starLoadFile, IMAGE_BITMAP, 0, 0,
		LR_CREATEDIBSECTION | LR_LOADFROMFILE | LR_DEFAULTSIZE);

	if (this->IsEmpty())
	{
		return false;
	}

	GetObject(m_BitmapHandle, sizeof(m_BitmapInfo), &m_BitmapInfo);
	return true;
}

void BImage::SetRotate(double value)
{
}

bool BImage::Load(HBITMAP bitmapHandle)
{
	return false;
}

bool BImage::Relase()
{
	return false;
}

bool BImage::IsEmpty() const
{
	return m_BitmapHandle == NULL; // ���⼭ nullptr�� ���� ���� �߻� ����
}

HBITMAP BImage::GetBitmapHandle() const
{
	return HBITMAP();
}

const BITMAP& BImage::GetBitmapInfo() const
{
	// TODO: ���⿡ return ���� �����մϴ�.
}

void BImage::DrawBitmap(HDC hdc, int x, int y, int width, int height) const
{
}

void BImage::DrawBitmapByCrop(HDC hdc, int x, int y, int width, int height, int sx, int sy, int sw, int sh) const
{
}

void BImage::SetRansparentColor(DWORD color)
{
}

DWORD BImage::GetTransparentColor()
{
	return 0;
}
