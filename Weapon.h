#pragma once
#include "Equippable.h"

struct WeaponData
{
	u_int reach = 0;
	double attackValue = 0.0;
	u_int attackSpeed = 0;

	WeaponData() = default;
	WeaponData(const u_int& _reach, const double _attackValue, const u_int& _attackSpeed);
};

class Weapon : public Equippable
{
	WeaponData weaponData;

public:

	FORCEINLINE WeaponData GetWeaponData() const
	{
		return weaponData;
	}
	FORCEINLINE void SetWeaponData(const WeaponData& _weaponData)
	{
		weaponData = _weaponData;
	}

	Weapon() = default;
	Weapon(const Weapon& _other);
	Weapon(const WeaponData& _weaponData, const EquippableData& _equippableData, const ItemData& _itemData);
};