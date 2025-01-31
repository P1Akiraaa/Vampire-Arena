#pragma once
#include "Macro.h"

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

struct ItemData
{
	string name = "Unknown";
	string description = "Description";
	Texture texture;
	u_int upgradePrice = 0;
	RarityType rarity = RT_JUNK;
};

class Item
{

protected:
	ItemData itemData;

public:
	FORCEINLINE ItemData GetItemData() const
	{
		return itemData;
	}
	FORCEINLINE void SetItemData(const ItemData& _itemData)
	{
		itemData = _itemData;
	}
protected:
	string GetRarityName();
	string GetFlavorText();
};