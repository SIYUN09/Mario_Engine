#pragma once
#include "..\\MarioEngine_SOURCE\\MarioResources.h"
#include "..\\MarioEngine_SOURCE\\MarioTexture.h"

namespace Mario
{
	void LoadResources()
	{
		Resources::Load<graphcis::Texture>(L"BG", L"..\\Resource\\title1.png");
	}
}