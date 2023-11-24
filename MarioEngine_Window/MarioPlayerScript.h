#pragma once
#include "..\\MarioEngine_SOURCE\\MarioScript.h"


namespace Mario
{
	class PlayerScript : public Script
	{
	public:
		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;


	private:

	};
}

