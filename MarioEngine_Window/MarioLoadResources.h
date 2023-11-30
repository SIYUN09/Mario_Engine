#pragma once
#include "..\\MarioEngine_SOURCE\\MarioResources.h"
#include "..\\MarioEngine_SOURCE\\MarioTexture.h"

namespace Mario
{
	void LoadResources()
	{
		
		//TitleScene
		Resources::Load<graphcis::Texture>(L"TT1", L"..\\Resource\\title1.png");
		
		//LoadingScene
		Resources::Load<graphcis::Texture>(L"TT2", L"..\\Resource\\title2.png");
		
		//PlayScene
		Resources::Load<graphcis::Texture>(L"MarioRightMove", L"..\\Resource\\MarioRightMove.bmp");
		Resources::Load<graphcis::Texture>(L"MarioLeftMove", L"..\\Resource\\MarioLeftMove.bmp");
		Resources::Load<graphcis::Texture>(L"Map", L"..\\Resource\\WORLD.png");
		/*Resources::Load<graphcis::Texture>(L"En", L"..\\Resource\\MASH.png");*/

		//EndScene
		Resources::Load<graphcis::Texture>(L"ED", L"..\\Resource\\end.png");
		
	}
}