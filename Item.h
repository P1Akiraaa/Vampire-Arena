#pragma once
#include "Macro.h"

enum EquipmentType
{
	ET_SLASHING,
	ET_CRUSHING,
	ET_PIERCING,

	ET_COUNT
};

enum RarityType
{
	RT_JUNK = 1,
	RT_COMMON,
	RT_UNCOMMON,
	RT_RARE,
	RT_EPIC,
	RT_LEGENDARY,
	RT_SANGUINE,

	RT_COUNT
};

class Item
{
protected:
	string name;
	string description;
	int upgradePrice;
	EquipmentType type;
	RarityType rarity;

public:
	FORCEINLINE string GetName() const
	{
		return name;
	}
	FORCEINLINE string GetDescription() const
	{
		return description;
	}
	FORCEINLINE int GetUpgradePrice() const
	{
		return upgradePrice * rarity;
	}
	FORCEINLINE int GetRarity() const
	{
		return rarity;
	}

public:
	Item() = default;
	Item(const string& _name, const string& _description, const int _upgradePrice,
		const EquipmentType& _type, const RarityType& _rarity);
};