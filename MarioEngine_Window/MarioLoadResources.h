#pragma once
#include "..\\MarioEngine_SOURCE\\MarioResources.h"
#include "..\\MarioEngine_SOURCE\\MarioTexture.h"

namespace Mario
{
	void LoadResources()
	{
		
		//TitleScene
		Resources::Load<graphcis::Texture>(L"TT1", L"..\\Resource\\BMP\\Title1.bmp");
		
		//LoadingScene
		Resources::Load<graphcis::Texture>(L"TT2", L"..\\Resource\\BMP\\Title2.bmp");
		
		//PlayScene
		Resources::Load<graphcis::Texture>(L"MarioMove", L"..\\Resource\\BMP\\MarioRight.bmp");
		Resources::Load<graphcis::Texture>(L"Map", L"..\\Resource\\BMP\\World 1-1.bmp");
		/*Resources::Load<graphcis::Texture>(L"En", L"..\\Resource\\MASH.png");*/

		//EndScene
		Resources::Load<graphcis::Texture>(L"ED", L"..\\Resource\\BMP\\end.bmp");
		
	}
}