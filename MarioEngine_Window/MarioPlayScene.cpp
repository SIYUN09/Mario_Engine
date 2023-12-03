#include "MarioPlayScene.h"
#include "MarioGameObject.h"
#include "MarioPlayer.h"
#include "MarioTransform.h"
#include "MarioSpriteRenderer.h"
#include "MarioInput.h"
#include "MarioTitleScene.h"
#include "MarioSceneManager.h"
#include "MarioObject.h"
#include "MarioTexture.h"
#include "MarioResources.h"
#include "MarioPlayerScript.h"
#include "MarioCamera.h"
#include "MarioRenderer.h"
#include "MarioAnimator.h"


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
		// main camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::BackGround, Vector2(393.0f, 388.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		
		GameObject* bg = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround /*Vector2(0.0f, 10.0f)*/);
		SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		bgSr->SetSize(Vector2(3.0f, 3.0f));

		graphcis::Texture* bgTexture = Resources::Find<graphcis::Texture>(L"Map");
		bgSr->SetTexture(bgTexture);

		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		PlayerScript* plScript = mPlayer->AddComponent<PlayerScript>();
		cameraComp->SetTarget(mPlayer);
		graphcis::Texture* PMTexture = Resources::Find<graphcis::Texture>(L"MarioMove");
		Animator* PManimator = mPlayer->AddComponent<Animator>();
		PManimator->CreateAnimation(L"RightWalk", PMTexture
			, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), Vector2::Zero, 4, 0.1f);
		PManimator->CreateAnimation(L"Stand", PMTexture
			, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), Vector2::Zero, 1, 0.1f);
	
		PManimator->PlayAnimation(L"Stand", false);
		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(80.0f, 592.0f));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.5f, 2.5f));
		

		

		//GameObject* En = object::Instantiate<GameObject>
		//	(enums::eLayerType::Enemy, Vector2(700.0f, 580.0f));
		//SpriteRenderer* EnSr = En->AddComponent<SpriteRenderer>();
		//EnSr->SetSize(Vector2(1.5f, 1.5f));
		//
		//graphcis::Texture* EnTexture = Resources::Find<graphcis::Texture>(L"En");
		//EnSr->SetTexture(EnTexture);

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
			SceneManager::LoadScene(L"EndScene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		//wchar_t str[50] = L"Play Scene";
		//TextOut(hdc, 0, 0, str, 10);
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