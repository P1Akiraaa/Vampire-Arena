#pragma once
#include "Character.h"

class Player : public Character
{
	int gold;

public:
	FORCEINLINE void SetGold(const int _gold)
	{
		gold = _gold;
	}

public:
	Player(const RectangleShapeData& _data, const string& _name = "Player");

public:
	virtual void Attack(const int _amount) override;
	virtual void Defend() override;
};

