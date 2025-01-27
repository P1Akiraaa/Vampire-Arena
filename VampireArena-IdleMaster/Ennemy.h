#pragma once
#include "Entity.h"

class Ennemy : public Entity
{
	int goldToDrop;

public:
	FORCEINLINE int GetGoldToDrop() const
	{
		return goldToDrop;
	}

public:
	Ennemy();
	Ennemy(const string& _name, const int _life, const int _speed, const int _golToDrop, const bool _isFrenzied = false);
};