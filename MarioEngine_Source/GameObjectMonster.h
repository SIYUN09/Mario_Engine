#pragma once
#include "CommonInclude.h"

namespace Mario
{
	class GameObjectMonster
	{
	public:
		GameObjectMonster();
		~GameObjectMonster();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}

		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }


	private:

		float mX;
		float mY;
		float mSpeed;
	};
}

