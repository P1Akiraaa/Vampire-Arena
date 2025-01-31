#pragma once
#include "Component.h"

enum CollisionType
{
	CT_NONE,
	CT_OVERLAP,
	CT_BLOCK
};

enum LayerType
{
	LT_STATIC,
	LT_DYNAMIC,

	// =========== \\


};

class CollisionComponent : public Component
{
	LayerType layer;
	CollisionType collision;

public:
	CollisionComponent(Actor* _owner,const CollisionType& _collision,const LayerType& _layer);
};