#pragma once
#include "Equipable.h"

class Weapon : public Equipable
{

public :

	inline double GetReach() const
	{
		return REACH;
	}

	inline double GetAttackValue() const
	{
		return ((ATTACK * WEIGHT) * (1 + (double(RARITY) * 0.1)) * 0.9);
	}

public :
	// Random
	Weapon();
	// Copie
	Weapon(const Weapon& _other);
	// Manuel
	Weapon(ElementType _elementType, double _weight = 1, RarityType _rarity = RT_JUNK);

private:
	string ComputeWeaponName();
	string ComputeWeaponDescription();
	Texture GetWeaponTexture();
};

