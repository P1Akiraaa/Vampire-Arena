#include "Armor.h"

ArmorData::ArmorData(const u_int& _resistance)
{
	resistance = _resistance;
}

Armor::Armor(const ArmorData& _armorData, const EquippableData& _equippableData, const ItemData& _itemData)
	: Equippable(_equippableData, _itemData)
{
	armorData = _armorData;
}

Armor::Armor(const Armor& _other)
	: Equippable(_other.equippableData, _other.itemData)
{
	armorData = _other.armorData;
}
