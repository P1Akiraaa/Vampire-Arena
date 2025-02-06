#include "PlayerMovement.h"
#include "Actor.h"

PlayerMovement::PlayerMovement(Actor* _owner) : MovementComponent(_owner)
{
	direction = Vector2f(0.0f, 0.0f);
	speed = 100.0f;
}

PlayerMovement::PlayerMovement(Actor* _owner, const PlayerMovement* _other) : MovementComponent(_owner)
{
	direction = _other->direction;
	speed = 150.0f;
}

void PlayerMovement::Tick(const float _deltaTime)
{
	Move(_deltaTime);
}

void PlayerMovement::Move(const float _deltaTime)
{
	owner->Move(direction * _deltaTime * speed);
}

void PlayerMovement::ProcessInputs(const Vector2f& _offset)
{
	direction += _offset;
	direction.x = direction.x >= 1.0f ? 1.0f : direction.x;
	direction.y = direction.y >= 1.0f ? 1.0f : direction.y;
	direction.x = direction.x <= -1.0f ? -1.0f : direction.x;
	direction.y = direction.y <= -1.0f ? -1.0f : direction.y;

	if (direction.x + direction.y == 0.0f) return;
	direction = direction.normalized();
	
	
}
