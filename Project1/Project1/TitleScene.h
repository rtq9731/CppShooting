#pragma once
#include "Scene.h"
#include "BBasicSys.h"

class TitleScene : public Scene
{
public:
	TitleScene();
	virtual ~TitleScene();

public:
	void Init() override;
	void Update(float deltaTime) override;
	void Render(HDC hdc, float deltaTime) override;
	void Release() override;

private:
	POINT m_StartBtnPos; // 시작 버튼 위치
	RECT m_StartBtnRect; // 시작 버튼 사각형 -> 나중에 버튼 자체를 클래스로 빼주면 좋다.
};

