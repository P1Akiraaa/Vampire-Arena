#pragma once
#include "Item.h"


enum ElementType
{
	ET_SLASH,
	ET_BLUNT,
	ET_PIERCE,
};

struct EquippableData
{
	bool saboted = false;
	u_int equippableStat = 0;
	u_int weight = 0;
	ElementType element;

	EquippableData() = default;
	EquippableData(const bool _saboted, const u_int& _equippableStat,
		const u_int _weight, const ElementType& _element);
};

class Equippable : public Item
{

protected:
	EquippableData equippableData;

public:

	FORCEINLINE EquippableData GetEquippableData() const
	{
		return equippableData;
	}
	FORCEINLINE void SetEquippableData(const EquippableData& _equippableData)
	{
		equippableData = _equippableData;
	}

public:
	Equippable() = default;
	Equippable(const Equippable& _other);
	Equippable(const EquippableData& _data, const ItemData& _itemData);
};