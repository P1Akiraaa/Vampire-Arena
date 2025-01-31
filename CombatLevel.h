#pragma once
#include "Level.h"
#include "Character.h"
#include "Game.h"

class CombatLevel : public Game
{
	MeshActor* backGround;
	Character* player;
	Character* enemy;
	u_int round;

public:
	CombatLevel() = default;
	CombatLevel(Character* _player, Character* _enemy);

public:
	virtual void Start() override;
	virtual bool Update() override;
	virtual void Stop() override;

private:
	void Round();
};