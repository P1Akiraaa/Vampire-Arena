#pragma once
#include "Level.h"
#include "Character.h"

class CombatLevel : public Level
{
	Character* player;
	Character* enemy;

	u_int round;

public:
	CombatLevel() = default;
	CombatLevel(Character* _player, Character* _enemy);

public:
	void Start();
	void End();

private:
	void Round();
};