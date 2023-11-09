#include "MarioGameObject.h"
#include "MarioInput.h"
namespace Mario
{
	GameObject::GameObject()
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		if (Input::GetKey(eKeyCode::A))
		{
			mX -= 1;
		}

		if (Input::GetKey(eKeyCode::D))
		{
			mX += 1;
		}

		if (Input::GetKey(eKeyCode::W))
		{
			mY -= 1;
		}

		if (Input::GetKey(eKeyCode::S))
		{
			mY += 1;
		}
	}

	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render(HDC hdc)
	{
		//파랑 브러쉬 생성
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		// 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환값 반환
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}
}