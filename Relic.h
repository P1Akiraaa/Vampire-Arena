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
	Relic(Relic&& _other);
	Relic(Relic* _other);
	Relic() = default;

public:
	void Effect() {}; //TODO
};