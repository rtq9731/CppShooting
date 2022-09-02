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
	* LoadImage의 파라미터는 다음과 같다.
	* HINSTANCE, 파일이름, 타입, x, y, 로드 옵션
	* 타입 : IMAGE_BITMAP(0), IMAGE_ICON(1), IMAGE_COURSOR(2)
	* x, y : 이미지의 크기를 말하는데 만약에 이 값이 전부 0이면서 LR_DEFAULTSIZE가 옵션으로 오면
	*	시스템의 XM_CXICON을 이용해서 크기를 측정하고 되고
	*	만약 LR_DEFAULT_SIZE가 설정되어 있지 않다면 리소스가 원래 크기로 로드 된다.
	* 
	* DIB = Device_Independent Bitmap = 장치 독립적 비트맵, 색ㅈ 정보 테이블을 가지고 있는 비트맵
	* LR_LOADFROMFILE : 리소스 대신 파일 경로를 이용하여 불러올 것
	* 
	* GetModuleHandle => Moudle에 대한 인스턴스핸들, dll이나 exe에 사용하는데,
	* 여기서는 nullptr을 넣으면 현재 인스턴스의 핸들이 넘어오게 됨.
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
	return m_BitmapHandle == NULL; // 여기서 nullptr을 쓰면 문제 발생 가능
}

HBITMAP BImage::GetBitmapHandle() const
{
	return HBITMAP();
}

const BITMAP& BImage::GetBitmapInfo() const
{
	// TODO: 여기에 return 문을 삽입합니다.
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
