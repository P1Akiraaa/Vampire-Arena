#include "RotateToTargetComponent.h"
#include "Actor.h"

RotateToTargetComponent::RotateToTargetComponent(Actor* _owner) : MovementComponent(_owner)
{
	hasLauch = false;
	speed = 10.0f;
	startingRotation = 0.0f;
	endRotation = 0.0f;
	duration = 0.0f;
	targetCoordinate = { 0.0f, 0.0f };
}

RotateToTargetComponent::RotateToTargetComponent(Actor* _owner, const RotateToTargetComponent* _other)
	:MovementComponent(_owner)
{
	hasLauch = _other->hasLauch;
	speed = _other->speed;
	startingRotation = _other->startingRotation;
	endRotation = _other->endRotation;
	duration = _other->duration;
	targetCoordinate = _other->targetCoordinate;
}

void RotateToTargetComponent::Tick(const float _deltaTime)
{
	if (hasLauch)
	{
		const float _step = speed * _deltaTime;
		duration += _step;
		float _rotation = Lerp(startingRotation, endRotation, duration);
		if (endRotation - startingRotation > 3.0f)
		{
			_rotation = Lerp(-startingRotation, endRotation, duration);
		}
		else if (endRotation - startingRotation < -3.0f)
		{
			_rotation = Lerp(-startingRotation, endRotation, duration);
		}
		owner->SetRotation(radians(_rotation));
		if (!IsOverRadian())
		{
			hasLauch = false;
		}
	}
}

void RotateToTargetComponent::Launch()
{
	duration = 0.0f;
	const Vector2f& _vector = owner->GetForwardVector();
	const float _atan = atan2f(_vector.y, _vector.x);
	startingRotation = _atan;
	endRotation = ComputeRotation();
	hasLauch = true;
}

Vector2f RotateToTargetComponent::ComputeTargetDirection() const
{
	const Vector2f& _ownerCoords = owner->GetPosition();
	const float _x = targetCoordinate.x - _ownerCoords.x;
	const float _y = targetCoordinate.y - _ownerCoords.y;
	return { _x, _y };
}

float RotateToTargetComponent::ComputeRotation()
{
	const Vector2f& _vector = ComputeTargetDirection().normalized();
	const float _atan = atan2f(_vector.y, _vector.x);
	return _atan;
}

bool RotateToTargetComponent::IsOverRadian()
	{
		const Vector2f& _vector = owner->GetForwardVector();
		const float _atan = atan2f(_vector.y, _vector.x);
		return IsHigther() ? _atan >= endRotation : _atan <= endRotation;
	}
