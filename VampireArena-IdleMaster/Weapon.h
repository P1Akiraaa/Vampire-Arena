#pragma once
#include "Equipable.h"

class Weapon : public Equipable
{

public :

	FORCEINLINE double GetReach() const
	{
		return weight;
	}

	FORCEINLINE double GetAttackValue() const
	{
		return ((equipableStat * weight) * (1 + (static_cast<int>(rarity) * 0.1)) * 0.9);
	}

public:
	Weapon() = default;
};