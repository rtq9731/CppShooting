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
	POINT m_StartBtnPos; // ���� ��ư ��ġ
	RECT m_StartBtnRect; // ���� ��ư �簢�� -> ���߿� ��ư ��ü�� Ŭ������ ���ָ� ����.
};

