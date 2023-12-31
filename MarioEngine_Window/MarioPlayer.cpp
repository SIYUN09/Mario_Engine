#include "MarioPlayer.h"
#include "MarioInput.h"
#include "MarioTransform.h"
#include "MarioTime.h"

namespace Mario
{
	void Player::Initialize()
	{
		GameObject::Initialize();
	}

	void Player::Update()
	{
		GameObject::Update();
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}