#pragma once
#include "Level.h"
#include "Player.h"
#include "Enemy.h"

class CombatLevel
{
	Player* player;
	Enemy* enemy;

public:
	CombatLevel() = default;
};

