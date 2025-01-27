#pragma once
#include "Equipable.h"

class Armor : public Equipable
{
	int weight;
	int resistance;

public:
	FORCEINLINE int GetResistance() const
	{
		return resistance;
	}
	FORCEINLINE int GetWeight() const
	{
		return weight;
	}

public:
	Armor() = default;
};

