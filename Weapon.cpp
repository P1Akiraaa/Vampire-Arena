#include "Weapon.h"

Weapon::Weapon(const Weapon& _other)
	: Equippable(_other.equippableData, _other.itemData)
{
	weaponData = _other.weaponData;
}

Weapon::Weapon(const WeaponData& _weaponData, const EquippableData& _equippableData
	, const ItemData& _itemData)
	: Equippable(_equippableData, _itemData)
{
	weaponData = _weaponData;
}

WeaponData::WeaponData(const u_int& _reach, const double _attackValue, const u_int& _attackSpeed)
{
	reach = _reach;
	attackValue = _attackValue;
	attackSpeed = _attackSpeed;
}