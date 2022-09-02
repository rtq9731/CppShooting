#pragma once

#include "BBasicStd.h"

class BImage
{
public:
	BImage();
	BImage(const TCHAR* strLoadFile);
	// w_char_t 를 TCHAR로 변환하려면 const가 필요하다
	~BImage();

protected:
	HBITMAP m_BitmapHandle;
	BITMAP m_BitmapInfo;
	double m_rotateAngle = 0;

public:
	bool Load(const TCHAR* starLoadFile);
	bool Load(HBITMAP bitmapHandle);
	bool Relase();
	void SetRotate(double value);

	bool IsEmpty() const; 
	HBITMAP GetBitmapHandle() const;
	const BITMAP& GetBitmapInfo() const;
	
	void DrawBitmap(HDC hdc, int x, int y, int width, int height) const;
	void DrawBitmapByCrop(HDC hdc, int x, int y, int width, int height, int sx, int sy, int sw, int sh) const;

private:
	static DWORD m_TransparentColor;

public:
	static void SetRansparentColor(DWORD color);
	static DWORD GetTransparentColor();
};

