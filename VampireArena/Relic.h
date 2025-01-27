#pragma once
#include "Item.h"

class Relic : public Item
{
	int buffer;

public:
	FORCEINLINE int GetBuffer() const
	{
		return buffer;
	}
	
public:
	Relic() = default;

public:
	void Effect() {}; //TODO
};

