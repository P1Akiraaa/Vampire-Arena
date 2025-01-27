#pragma once
#include "Character.h"

class Enemy : public Character
{
	int goldToDrop;

public:
	FORCEINLINE void SetGoldToDrop(const int _gold, const bool _random = false)
	{
		if (_random)
		{
			goldToDrop = GetRandomNumberInRange(1, _gold);
		}
		else
		{
			goldToDrop = _gold;
		}
	}
	FORCEINLINE int GetGoldToDrop() const
	{
		return goldToDrop;
	}

public:
	Enemy(const RectangleShapeData& _data, const string& _name = "Character");

public:
	virtual void Attack(const int _amount) override;
	virtual void Defend() override;
};

