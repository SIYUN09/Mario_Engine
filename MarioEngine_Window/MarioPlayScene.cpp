#include "MarioPlayScene.h"
#include "MarioGameObject.h"
#include "MarioPlayer.h"
#include "MarioTransform.h"
#include "MarioSpriteRenderer.h"
#include "MarioInput.h"
#include "MarioTitleScene.h"
#include "MarioSceneManager.h"
#include "MarioObject.h"

namespace Mario
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		bg = object::Instantiate<Player>
			(enums::eLayerType::BackGround, Vector2(100.0f, 100.0f));
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->ImageLoad(L"D:\\AR50\\MarioEngine\\Resource\\World 1-1.png");

		// 게임 오브젝트 생성후에 레이어와 게임오브젝트들의 init함수를 호출
		Scene::Initialize();
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);
	}
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		//Transform* tr = bg->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
}