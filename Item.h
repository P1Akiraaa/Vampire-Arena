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

struct ItemData
{
	string name = "La non nommée";
	string description = "Feur";
	u_int upgradePrice = 0;
	EquipmentType equipmentType = ET_SLASHING;
	RarityType rarity = RT_JUNK;

	ItemData() = default;
	ItemData(const string& _name, const string& _description,
		const u_int& _upgradePrice, const EquipmentType& _equipmentType, const RarityType& _rarity);
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

public:
	Item() = default;
	Item(const ItemData& _data);
};