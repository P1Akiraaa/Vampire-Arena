#include "Item.h"

Item::Item(const string& _name, const string& _description, const int _upgradePrice, const EquipmentType& _type, const RarityType& _rarity)
{
	name = _name;
	description = _description;
	upgradePrice = _upgradePrice;
	type = _type;
	rarity = _rarity;
}