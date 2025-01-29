#include "Equippable.h"

Equippable::Equippable(const Equippable& _other)
	: Item(_other.itemData)
{
	equippableData = _other.equippableData;
}

Equippable::Equippable(const EquippableData& _data, const ItemData& _itemData)
	: Item(_itemData)
{
	equippableData = _data;
}

EquippableData::EquippableData(const bool _saboted, const u_int& _equippableStat, 
	const u_int _weight, const ElementType& _element)
{
	saboted = _saboted;
	equippableStat = _equippableStat;
	weight = _weight;
	element = _element;

}
