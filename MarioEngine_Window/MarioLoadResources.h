#pragma once
#include "..\\MarioEngine_SOURCE\\MarioResources.h"
#include "..\\MarioEngine_SOURCE\\MarioTexture.h"

namespace Mario
{
	void LoadResources()
	{
		Resources::Load<graphcis::Texture>(L"PackMan", L"..\\Resource\\MARIO.png");
		Resources::Load<graphcis::Texture>(L"Map", L"..\\Resource\\WORLD.png");
	}
}