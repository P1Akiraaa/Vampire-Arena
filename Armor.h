#pragma once
#include "Equipable.h"

class Armor : public Equipable
{

public :
	
	inline double GetWeight() const
	{
		return WEIGHT;
	}

	inline double GetResistance() const
	{
		return ((RESISTANCE / 2) * WEIGHT) * (double(RARITY) * 0.1);
	}

public :
	// Random
	Armor();
	// Copie
	Armor(const Armor& _other);
	// Manuel
	Armor(ElementType _elementType, double _weight, RarityType _rarity = RT_JUNK);

	string ComputeArmorName();
	string ComputeArmorDescription();
	Texture GetArmorTexture();
};

