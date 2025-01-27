#pragma once
#include "Equipable.h"

class Armor : public Equipable
{
	int resistance;

public:
	FORCEINLINE int GetResistance() const
	{
		return resistance;
	}
	FORCEINLINE int GetWeight() const
	{
		return ((equipableStat / 2) * weight) * (static_cast<int>(rarity) * 0.1);
	}

public:
	Armor() = default;
};