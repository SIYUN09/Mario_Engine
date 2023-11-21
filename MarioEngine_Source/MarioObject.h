#pragma once
#include "MarioComponent.h"
#include "MarioGameObject.h"
#include "MarioLayer.h"
#include "MarioScene.h"
#include "MarioSceneManager.h"
#include "MarioTransform.h"


namespace Mario::object
{
	template <typename T>
	static T* Instantiate(Mario::enums::eLayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(Mario::enums::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}
}