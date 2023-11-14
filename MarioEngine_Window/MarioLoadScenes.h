#pragma once
#include "..\\MarioEngine_SOURCE\\MarioSceneManager.h"

#include "MarioPlayScene.h"

namespace Mario
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"EndScene");
		//SceneManager::CreateScene<TitleScene>(L"TitleScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}