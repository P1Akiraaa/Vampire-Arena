#pragma once
#include "Equipable.h"

class Weapon : public Equipable
{
	int reach;
	int attackValue;
	int attackSpeed;

public:
	FORCEINLINE int GetReach() const
	{
		return reach;
	}
	FORCEINLINE int GetAttackValue() const
	{
		return attackValue;
	}
	FORCEINLINE int GetAttackSpeed() const
	{
		return attackSpeed;
	}
};

