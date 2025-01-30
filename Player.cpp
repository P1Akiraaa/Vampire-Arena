#include "Player.h"

Player::Player(const RectangleShapeData& _data, const CharacterData& _characterData) : Character(_data, _characterData)
{
}

void Player::Construct()
{
	Super::Construct();

	const float _timeBetween = 0.1f;
	const Vector2i& _spriteSize = Vector2i(50, 53);
	const vector<SpriteData>& _spritesData =
	{
		{ _timeBetween, Vector2i(0, 0), _spriteSize },
		{ _timeBetween, Vector2i(65, 0), _spriteSize },
		{ _timeBetween, Vector2i(128, 0), _spriteSize },
		{ _timeBetween, Vector2i(192, 0), _spriteSize },
		{ _timeBetween, Vector2i(259, 0), _spriteSize },
	};

	const AnimationData& _animationData = AnimationData(2.0f, _spritesData);

	animation->AddAnimation(new Animation("Default", GetMesh()->GetShape(), _animationData));
	animation->SetCurrentAnimation("Default");
	animation->StartAnimation();
}
