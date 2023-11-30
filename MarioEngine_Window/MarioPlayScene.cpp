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
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(393.0f, 388.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		//camera->AddComponent<PlayerScript>();



		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player, Vector2(50.0f, 550.0f));
		mPlayer->AddComponent<PlayerScript>();
		/*SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		sr->SetSize(Vector2(1.5f, 1.5f));*/
		graphcis::Texture* PRTexture = Resources::Find<graphcis::Texture>(L"MarioRightMove");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"RightWalk", PRTexture
			, Vector2(0.0f, 0.0f), Vector2(18.8f, 30.0f), Vector2::Zero, 5, 0.1f);

	
		graphcis::Texture* PLTexture = Resources::Find<graphcis::Texture>(L"MarioLeftMove");
		
		animator->CreateAnimation(L"LeftWalk", PLTexture
			, Vector2(187.6f, 0.0f), Vector2(18.8f, 30.0f), Vector2::Zero, 5, 0.1f);


		animator->PlayAnimation(L"Basic", false);
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.5f, 2.5f));

		//움직임
		/*graphcis::Texture* packmanTexture = Resources::Find<graphcis::Texture>(L"Cat");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"CatFrontMove", packmanTexture
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.5f);

		animator->PlayAnimation(L"CatFrontMove", true);*/
		/*sr->SetTexture(packmanTexture);*/

		/*graphcis::Texture* Pt = Resources::Find<graphcis::Texture>(L"PM");*/
		/*sr->SetTexture(Pt);*/

		GameObject* bg = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround/*, Vector2(100.0f, 100.0f)*/);
		SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		bgSr->SetSize(Vector2(3.0f, 3.0f));

		graphcis::Texture* bgTexture = Resources::Find<graphcis::Texture>(L"Map");
		bgSr->SetTexture(bgTexture);

	/*	GameObject* En = object::Instantiate<GameObject>
			(enums::eLayerType::Enemy, Vector2(700.0f, 580.0f));
		SpriteRenderer* EnSr = En->AddComponent<SpriteRenderer>();
		EnSr->SetSize(Vector2(1.5f, 1.5f));

		graphcis::Texture* EnTexture = Resources::Find<graphcis::Texture>(L"En");
		EnSr->SetTexture(EnTexture);*/

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