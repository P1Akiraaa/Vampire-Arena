#pragma once
#include "MovementComponent.h"

class RotateToTargetComponent : public MovementComponent
{
	bool hasLauch; 
	float startingRotation;
	float endRotation;
	float duration;
	Vector2f targetCoordinate;

public:
	FORCEINLINE bool IsHigther()
	{
		return startingRotation > endRotation;
	}

	FORCEINLINE void SetTargetCoordinate(const Vector2f& _targetCoordinate)
	{
		targetCoordinate = _targetCoordinate;
	}

public:
	RotateToTargetComponent(Actor* _owner);
	RotateToTargetComponent(Actor* _owner, const RotateToTargetComponent* _other);

protected:
	virtual void Tick(const float _deltaTime) override;

private:
	bool IsOverRadian();
	virtual Vector2f ComputeTargetDirection() const ;
	float ComputeRotation();
	//Vector2f RotateToward(const Vector2f& _foward, const Vector2f& _target,
	//	const float _maxRadiansDelta, const float _maxMagnitudeDelta);
public:
	void Launch();
};

