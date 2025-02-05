#include "Equipable.h"

int Equipable::GetSize()
{
	if (equipableData.weight <= 2 && equipableData.weight > 1.3)
	{
		return ES_LARGE;
	}
	else if (equipableData.weight <= 1.3 && equipableData.weight > 0.66)
	{
		return ES_MEDIUM;
	}
	else if (equipableData.weight <= 0.66 && equipableData.weight > 0)
	{
		return ES_LIGHT;
	}
}
