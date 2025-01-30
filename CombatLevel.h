#pragma once
#include "Level.h"
#include "Player.h"
#include "Enemy.h"
#include "Game.h"

class CombatLevel : public Game
{
	MeshActor* backGround;

	Player* player;
	Enemy* enemy;

	u_int round;

public:
	CombatLevel();
	CombatLevel(Player* _player, Enemy* _enemy);

public:
	virtual void Start() override;
	virtual bool Update() override;
	virtual void Stop() override;

private:
	void Round();
};