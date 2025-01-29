#include "Item.h"

ItemData::ItemData(const string& _name, const string& _description,
	const u_int& _upgradePrice, const EquipmentType& _equipmentType,
	const RarityType& _rarity)
{
	name = _name;
	description = _description;
	upgradePrice = _upgradePrice;
	equipmentType = _equipmentType;
	rarity = _rarity;
}

Item::Item(const ItemData& _data)
{
	itemData = _data;
}
