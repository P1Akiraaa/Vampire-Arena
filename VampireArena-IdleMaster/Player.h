#pragma once
#include "Entity.h"

class Player : public Entity
{
	int gold;

public:
	FORCEINLINE int GetGold() const
	{
		return gold;
	}

public:
	Player();
	Player(const string& _name, const int _life, const int _speed, const bool _isFrenzied = false, const int _gold);
};