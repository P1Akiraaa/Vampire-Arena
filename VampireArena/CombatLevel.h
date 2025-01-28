#pragma once
#include "Level.h"
#include "Player.h"
#include "Enemy.h"

class CombatLevel : public Level
{
	Player* player;
	Enemy* enemy;

public:
	CombatLevel() = default;

public:
	void Open();
};