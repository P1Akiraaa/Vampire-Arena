#pragma once
#include "MovementComponent.h"
class PlayerMovement :  public MovementComponent
{
	Vector2f direction;

public:
	FORCEINLINE void ResetX()
	{
		direction.x = 0;
	}
	FORCEINLINE void ResetY()
	{
		direction.y = 0;
	}
public:
	PlayerMovement(Actor* _owner);
	PlayerMovement(Actor* _owner, const PlayerMovement* _other);

protected:
	virtual void Tick(const float _deltaTime) override;

private:
	virtual void Move(const float _deltaTime)override;
public:
	void ProcessInputs(const Vector2f& _offset);
	
};

