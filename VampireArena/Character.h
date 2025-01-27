#pragma once
#include "MeshActor.h"
#include "Weapon.h"
#include "Relic.h"
#include "Armor.h"
#include "AttackSkill.h"

class Character : public MeshActor
{
	string name;
	int life;
	int lifeMax;
	int speed;
	bool isFrenzied;
	Weapon* weapon;
	Armor* armor;
	Relic* relic;
	AttackSkill* attackSkill;
	//int fame; //LATER

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
	FORCEINLINE Weapon* GetWeapon() const
	{
		return weapon;
	}
	FORCEINLINE Armor* GetArmor() const
	{
		return armor;
	}
	FORCEINLINE Relic* GetRelic() const
	{
		return relic;
	}

public:
	Character() = default;
	Character(const RectangleShapeData& _data, const string& _name = "Character");
	virtual ~Character() = default;
public:
	virtual void Attack(const int _amount);
	virtual void Defend();
};