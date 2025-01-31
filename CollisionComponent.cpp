#include "CollisionComponent.h"
#include "HUD.h"
#include "Button.h"

using namespace UI;

CollisionComponent::CollisionComponent(Actor* _owner, const CollisionType& _collision, const LayerType& _layer) : Component(_owner)
{
	layer = _layer;
	collision = _collision;
}

