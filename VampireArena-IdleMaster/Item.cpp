#include "Item.h"

Item::Item(const string& _name, const string& _description, const int _upgradePrice, const RarityType& _rarity)
{
	name = _name;
	description = _description;
	upgradePrice = _upgradePrice;
	rarity = _rarity;
}