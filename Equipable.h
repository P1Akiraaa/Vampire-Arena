#pragma once
#include "Item.h"

enum ElementType
{
	ET_SLASH,
	ET_BLUNT,
	ET_PIERCE,
};

class Equipable : public Item
{
protected:
	bool isSaboted;
	int equipableStat;
	int weight;
	ElementType element;

public:

	inline bool GetIsSaboted() const
	{
		return isSaboted;
	}

public:
	Equipable() = default;
	Equipable(const string& _name, const string& _description, const int _upgradePrice, const EquipmentType& _type, const RarityType& _rarity,
		const int _equipableStat, const double _weight, const ElementType& _element, const bool _isSaboted = false);
};