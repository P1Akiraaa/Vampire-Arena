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
	FORCEINLINE double GetAttackValue() const
	{
		return ((equipableStat * weight) * (1 + (static_cast<int>(rarity) * 0.1)) * 0.9);
	}
	FORCEINLINE int GetAttackSpeed() const
	{
		return attackSpeed;
	}
};