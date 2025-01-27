#pragma once
#include "CoreMinimal.h"

enum RarityType
{
	RT_JUNK = 1,
	RT_COMMON,
	RT_UNCOMMON,
	RT_RARE,
	RT_EPIC,
	RT_LEGENDARY,
	RT_SANGUINE,
};

class Item
{
protected :
	string name;
	string description;
	int upgradePrice;
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

	Item(const string& _name, const string& _description, const int _upgradePrice, const RarityType& _rarity);
};

