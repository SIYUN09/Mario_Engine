#include "MarioSpriteRenderer.h"
#include "MarioGameObject.h"
#include "MarioTransform.h"
#include "MarioTexture.h"
#include "MarioRenderer.h"

namespace Mario
{
	SpriteRenderer::SpriteRenderer()
		: Component(enums::eComponentType::SpriteRenderer)
		, mTexture(nullptr)
		, mSize(Vector2::One)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{


	}
	void SpriteRenderer::Update()
	{

	}

	void SpriteRenderer::LateUpdate()
	{
	}

	void SpriteRenderer::Render(HDC hdc)
	{
		if (mTexture == nullptr) //텍스처 세팅 해주세요!
			assert(false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos = renderer::mainCamera->CaluatePosition(pos);
		if (mTexture->GetTextureType()
			== graphcis::Texture::eTextureType::Bmp)
		{
			//https://blog.naver.com/power2845/50147965306
			TransparentBlt(hdc, pos.x, pos.y
				, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y
				, mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight()
				, RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType()
			== graphcis::Texture::eTextureType::Png)
		{
			Gdiplus::Graphics graphcis(hdc);
			graphcis.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect(pos.x, pos.y
					, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y));
		}
	}

}