#pragma once
#include "GameObjectMonster.h"

namespace Mario
{
	GameObjectMonster::GameObjectMonster()
	{

	}

	GameObjectMonster::~GameObjectMonster()
	{

	}

	void GameObjectMonster::Update()
	{
		if (mY <= 0 || mX <= 0)
		{
			mSpeed = 1;
		}
		else if (mX + 100 >= 400 || mY + 100 >= 500)
		{
			mSpeed = -1;
		}

		mX += mSpeed;
		mY += mSpeed;
	}

	void GameObjectMonster::LateUpdate()
	{

	}

	void GameObjectMonster::Render(HDC hdc)
	{
		HBRUSH GreenBrush = CreateSolidBrush(RGB(0, 255, 0));
		HBRUSH OldBrush = (HBRUSH)SelectObject(hdc, GreenBrush);

		Rectangle(hdc, mX + 100, mY + 100, mX + 150, mY + 150);

		SelectObject(hdc, OldBrush);
		DeleteObject(GreenBrush);
	}
}