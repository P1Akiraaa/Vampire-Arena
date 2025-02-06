#include "TrianglePointer.h"


TrianglePointer::TrianglePointer() : TriangleActor(30.0f, "Ball")
{
	rotate = CreateComponent<RotateToTargetComponent>(); 
	move = CreateComponent<PlayerMovement>();
	playerAction = nullptr;
}

TrianglePointer::TrianglePointer(const TrianglePointer& _other) : TriangleActor(_other)
{
	rotate = CreateComponent<RotateToTargetComponent>(_other.rotate);
	move = CreateComponent<PlayerMovement>(_other.move);
	playerAction = _other.playerAction; 
}

void TrianglePointer::Construct()
{
	Super::Construct(); 
	playerAction = M_INPUT.CreateActionMap("PlayerActions");
	playerAction->AddAction("RotateToTarget", ActionData(MouseMoved), [&](const Vector2f& _position)
		{this->GetRotateComponent()->SetTargetCoordinate(_position);
	this->GetRotateComponent()->Launch();
		});

	playerAction->AddAction("MoveRight", ActionData(KeyHold, Key::D), [&]()
		{this->GetMovementComponent()->ProcessInputs({ 1.0f,0.0f }); });
	playerAction->AddAction("MoveLeft", ActionData(KeyHold, Key::Q), [&]()
		{this->GetMovementComponent()->ProcessInputs({ -1.0f,0.0f }); });
	playerAction->AddAction("MoveUp", ActionData(KeyHold, Key::Z), [&]()
		{this->GetMovementComponent()->ProcessInputs({ 0.0f, -1.0f }); });
	playerAction->AddAction("MoveDown", ActionData(KeyHold, Key::S), [&]()
		{this->GetMovementComponent()->ProcessInputs({ 0.0f, 1.0f }); });

	playerAction->AddAction("ReleaseKeyD", ActionData(KeyReleased, Key::D), [&]()
		{this->GetMovementComponent()->ResetX(); });
	playerAction->AddAction("ReleaseKeyQ", ActionData(KeyReleased, Key::Q), [&]()
		{this->GetMovementComponent()->ResetX(); });
	playerAction->AddAction("ReleaseKeyZ", ActionData(KeyReleased, Key::Z), [&]()
		{this->GetMovementComponent()->ResetY(); });
	playerAction->AddAction("ReleaseKeyS", ActionData(KeyReleased, Key::S), [&]()
		{this->GetMovementComponent()->ResetY(); });
	playerAction->Enable();
}
