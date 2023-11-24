#include "MarioLoadingScene.h"
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

namespace Mario
{
	LoadingScene::LoadingScene()
	{
	}
	LoadingScene::~LoadingScene()
	{
	}
	void LoadingScene::Initialize()
	{
		// main camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None);
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		//camera->AddComponent<PlayerScript>();


		//���ӿ�����Ʈ ��������� ���ҽ��� ���� Load�صθ� ����.
		//bg = object::Instantiate<Player>
		//	(enums::eLayerType::BackGround/*, Vector2(100.0f, 100.0f)*/);
		//SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();

		//graphcis::Texture* bg = Resources::Find<graphcis::Texture>(L"BG");
		//sr->SetTexture(bg);

		bg = object::Instantiate<GameObject>
			(enums::eLayerType::Loading/*, Vector2(100.0f, 100.0f)*/);
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->SetSize(Vector2(3.01f, 3.0f));


		graphcis::Texture* Tt2 = Resources::Find<graphcis::Texture>(L"TT2");
		sr->SetTexture(Tt2);

		// ���� ������Ʈ �����Ŀ� ���̾�� ���ӿ�����Ʈ���� init�Լ��� ȣ��
		Scene::Initialize();
	}

	void LoadingScene::Update()
	{
		Scene::Update();
	}
	void LoadingScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void LoadingScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void LoadingScene::OnEnter()
	{
	}
	void LoadingScene::OnExit()
	{
		//Transform* tr = bg->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
}