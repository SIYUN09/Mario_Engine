#pragma once
#include "..\\MarioEngine_SOURCE\\MarioScene.h"

namespace Mario
{
	class EndScene : public Scene
	{
	public:
		EndScene();
		~EndScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		class Player* bg;
	};
}
