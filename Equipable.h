#pragma once
#include "Item.h"


enum ElementType
{
	ET_SLASH = 1,
	ET_BLUNT,
	ET_PIERCE,
};

enum EquipableSize
{
	ES_LIGHT = 1,
	ES_MEDIUM,
	ES_LARGE,
};

struct EquipableData
{
	bool saboted = false;
	double equipableStat = 100;
	double weight = 1;
	ElementType element;
	EquipableSize size;
};

class Equipable : public Item
{

protected:
	EquipableData equipableData;

public:

	FORCEINLINE EquipableData GetEquipableData() const
	{
		return equipableData;
	}
	FORCEINLINE void SetEquipableData(const EquipableData& _equipableData)
	{
		equipableData = _equipableData;
	}
	
	int GetSize();
};