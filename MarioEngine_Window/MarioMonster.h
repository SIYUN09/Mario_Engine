#pragma once
#include "..\\MarioEngine_SOURCE\\MarioGameObject.h"

namespace Mario
{

	class Monster : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}

