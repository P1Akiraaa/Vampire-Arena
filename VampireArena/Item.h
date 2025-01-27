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
	RT_JUNK,
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
	inline string GetName() const
	{
		return name;
	}
	inline string GetDescription() const
	{
		return description;
	}
	inline int GetUpgradePrice() const
	{
		return upgradePrice * rarity;
	}
	inline int GetRarity() const
	{
		return rarity;
	}

public:
	Item() = default;
	Item(const string& _name, const string& _description, const int _upgradePrice,
		const EquipmentType& _type, const RarityType& _rarity);
};