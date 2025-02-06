#pragma once
#include "TriangleActor.h"
#include "RotateToTargetComponent.h"
#include "PlayerMovement.h"
#include "InputManager.h"
using namespace Input;

class TrianglePointer : public TriangleActor
{
	RotateToTargetComponent* rotate;
	PlayerMovement* move;
	ActionMap* playerAction; 

public:
	FORCEINLINE RotateToTargetComponent* GetRotateComponent()
	{
		return  rotate;
	}
	FORCEINLINE PlayerMovement* GetMovementComponent()
	{
		return  move;
	}

public:
	TrianglePointer();
	TrianglePointer(const TrianglePointer& _other);

public:
	virtual void Construct() override;

};

