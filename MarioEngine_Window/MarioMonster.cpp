#include "MarioMonster.h"
#include "MarioInput.h"
#include "MarioTransform.h"
#include "MarioTime.h"

namespace Mario
{
	void Monster::Initialize()
	{
		GameObject::Initialize();
	}

	void Monster::Update()
	{
		GameObject::Update();
	}

	void Monster::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Monster::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}