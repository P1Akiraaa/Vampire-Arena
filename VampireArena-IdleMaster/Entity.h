#pragma once
#include "AttackSkill.h"

class Entity
{
	string name;
	int life;
	int speed;
	bool isFrenzied;
	/*Weapon* currentWeapon;
	Armor* currentArmor;
	Relic* currentRelic;*/
	AttackSkill* attackSkill;

public:
	FORCEINLINE string GetName() const
	{
		return name;
	}
	FORCEINLINE int GetLife() const
	{
		return life;
	}
	FORCEINLINE int GetSpeed() const
	{
		return speed;
	}
	FORCEINLINE bool GetIsFrenzied() const
	{
		return isFrenzied;
	}
	/*FORCEINLINE Weapon* GetWeapon() const
	{
		return currentWeapon;
	}
	FORCEINLINE Armor* GetArmor() const
	{
		return currentArmor;
	}
	FORCEINLINE Relic* GetRelic() const
	{
		return currentRelic;
	}*/

public:
	Entity() = default;
	Entity(const string& _name, const int _life, const int _speed, const bool _isFrenzied = false);
	virtual ~Entity() = default;
};