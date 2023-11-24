#pragma once

namespace Mario::enums
{
	enum class eLayerType
	{
		None,
		BackGround,
		Enemy,
		Character,
		Player,
		Max = 16,
	};
	enum class eResourceType
	{
		Texture,
		AudioClip,
		Prefab,
		End,
	};

	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Script,
		Camera,
		End,
	};

}