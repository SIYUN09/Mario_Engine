#include "MarioPlayerScript.h"
#include "MarioInput.h"
#include "MarioTransform.h"
#include "MarioTime.h"
#include "MarioGameObject.h"
#include "MarioAnimator.h"

namespace Mario
{
	PlayerScript::PlayerScript()
		: mState(PlayerScript::eState::Basic)
		, mAnimator(nullptr)
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{


	}
	void PlayerScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case Mario::PlayerScript::eState::Basic:
			basic();
			break;
		case Mario::PlayerScript::eState::Walk:
			move();
			break;

		default:
			break;
		}

	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}

	void PlayerScript::basic()
	{


		if (Input::GetKey(eKeyCode::Right))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"RightWalk");
		}
		if (Input::GetKey(eKeyCode::Left))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"LeftWalk");
		}
	}

	void PlayerScript::move()
	{

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Up))
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			pos.y += 100.0f * Time::DeltaTime();
		}

		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::Right) || Input::GetKeyUp(eKeyCode::Left)
			|| Input::GetKeyUp(eKeyCode::Up) || Input::GetKeyUp(eKeyCode::Down))
		{
			mState = PlayerScript::eState::Basic;
			mAnimator->PlayAnimation(L"Basic", false);
		}
	}
}
/*if (Input::GetKey(eKeyCode::Right))
{
	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetPosition();
	pos.x += 100.0f * Time::DeltaTime();
	tr->SetPosition(pos);
}
if (Input::GetKey(eKeyCode::Left))
{
	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetPosition();
	pos.x -= 100.0f * Time::DeltaTime();

	tr->SetPosition(pos);
}
if (Input::GetKey(eKeyCode::Up))
{
	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetPosition();
	pos.y -= 100.0f * Time::DeltaTime();
	tr->SetPosition(pos);
}
if (Input::GetKey(eKeyCode::Down))
{
	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetPosition();
	pos.y += 100.0f * Time::DeltaTime();

	tr->SetPosition(pos);
}*/