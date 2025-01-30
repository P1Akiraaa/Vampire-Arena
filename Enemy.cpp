#include "Enemy.h"

Enemy::Enemy(const RectangleShapeData& _data, const CharacterData& _characterData) : Character(_data, _characterData)
{
}

void Enemy::Construct()
{
	Super::Construct();

	const float _timeBetween = 0.1f;
	const Vector2i& _spriteSize = Vector2i(63, 54);
	const vector<SpriteData>& _spritesData =
	{
		{ _timeBetween, Vector2i(16, 19), _spriteSize },
		{ _timeBetween, Vector2i(84, 19), _spriteSize },
		{ _timeBetween, Vector2i(150, 19), _spriteSize },
		{ _timeBetween, Vector2i(218, 19), _spriteSize },
		{ _timeBetween, Vector2i(279, 19), _spriteSize },
		{ _timeBetween, Vector2i(345, 19), _spriteSize },
	};

	const AnimationData& _animationData = AnimationData(2.0f, _spritesData);

	animation->AddAnimation(new Animation("Default", GetMesh()->GetShape(), _animationData));
	animation->SetCurrentAnimation("Default");
	animation->StartAnimation();
}
