#pragma once
#include "..\\MarioEngine_SOURCE\\MarioSceneManager.h"

#include "MarioPlayScene.h"
#include "MarioTitleScene.h"
#include "MarioEndScene.h"
#include "MarioLoadingScene.h"

namespace Mario
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<LoadingScene>(L"LoadingScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<EndScene>(L"EndScene");
		

		SceneManager::LoadScene(L"PlayScene");
		//SceneManager::LoadScene(L"TitleScene");
		//SceneManager::LoadScene(L"EndScene");
		//SceneManager::LoadScene(L"LoadingScene");
	}

}