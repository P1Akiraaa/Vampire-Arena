#pragma once
#include "Equippable.h"

struct ArmorData
{
	u_int resistance = 0;

	ArmorData() = default;
	ArmorData(const u_int& _armorData);
};

class Armor : public Equippable
{
	ArmorData armorData;

public:
	FORCEINLINE ArmorData GetArmorData() const
	{
		return armorData;
	}
	FORCEINLINE u_int GetResistance() const
	{
		return armorData.resistance;
	}
	FORCEINLINE u_int GetWeight() const
	{
		return ((equippableData.equippableStat / 2) * equippableData.weight) * (static_cast<int>(itemData.rarity) * 0.1);
	}

public:
	Armor() = default;
	Armor(const ArmorData& _armorData, const EquippableData& _equippableData,
		const ItemData& _itemData);
	Armor(const Armor& _other);
};