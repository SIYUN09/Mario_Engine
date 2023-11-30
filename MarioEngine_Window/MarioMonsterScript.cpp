#include "MarioMonsterScript.h"
#include "MarioInput.h"
#include "MarioTransform.h"
#include "MarioTime.h"
#include "MarioGameObject.h"
#include "MarioAnimator.h"

namespace Mario
{
	MonsterScript::MonsterScript()
		: mState(MonsterScript::eState::SitDown)
		, mAnimator(nullptr)
		, mTime(0.0f)
	{
	}
	MonsterScript::~MonsterScript()
	{
	}
	void MonsterScript::Initialize()
	{


	}
	void MonsterScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case Mario::MonsterScript::eState::SitDown:
			sitDown();
			break;
		case Mario::MonsterScript::eState::Walk:
			move();
			break;

		case Mario::MonsterScript::eState::Sleep:
			break;
		case Mario::MonsterScript::eState::LayDown:

			break;
		case Mario::MonsterScript::eState::Attack:
			break;
		default:
			break;
		}

	}
	void MonsterScript::LateUpdate()
	{
	}
	void MonsterScript::Render(HDC hdc)
	{
	}

	void MonsterScript::sitDown()
	{
		mTime += Time::DeltaTime();
		if (mTime > 3.0f)
		{
			mState = MonsterScript::eState::Walk;
			int direction = (rand() % 4);
			mDirection = (eDirection)direction;
			PlayWalkAnimationByDirection(mDirection);
			mTime = 0.0f;
		}
	}

	void MonsterScript::move()
	{
		mTime += Time::DeltaTime();
		if (mTime > 2.0f)
		{
			int isLayDown = rand() % 2;
			if (isLayDown)
			{
				mState = eState::LayDown;
				mAnimator->PlayAnimation(L"LayDown", false);
			}
			else
			{
				mState = eState::SitDown;
				mAnimator->PlayAnimation(L"SitDown", false);
			}
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		translate(tr);
	}

	void MonsterScript::layDown()
	{

	}

	void MonsterScript::PlayWalkAnimationByDirection(eDirection dir)
	{
		switch (dir)
		{
		case Mario::MonsterScript::eDirection::Left:
			mAnimator->PlayAnimation(L"LeftWalk", true);
			break;
		case Mario::MonsterScript::eDirection::Right:
			mAnimator->PlayAnimation(L"RightWalk", true);
			break;
		case Mario::MonsterScript::eDirection::Down:
			mAnimator->PlayAnimation(L"DownWalk", true);
			break;
		case Mario::MonsterScript::eDirection::Up:
			mAnimator->PlayAnimation(L"UpWalk", true);
			break;
		default:
			assert(false);
			break;
		}
	}
	void MonsterScript::translate(Transform* tr)
	{
		Vector2 pos = tr->GetPosition();
		switch (mDirection)
		{
		case Mario::MonsterScript::eDirection::Left:
			pos.x -= 100.0f * Time::DeltaTime();
			break;
		case Mario::MonsterScript::eDirection::Right:
			pos.x += 100.0f * Time::DeltaTime();
			break;
		case Mario::MonsterScript::eDirection::Down:
			pos.y += 100.0f * Time::DeltaTime();
			break;
		case Mario::MonsterScript::eDirection::Up:
			pos.y -= 100.0f * Time::DeltaTime();
			break;
		default:
			assert(false);
			break;
		}
		tr->SetPosition(pos);
	}
}