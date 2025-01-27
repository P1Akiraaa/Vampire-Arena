#pragma once
#include "MeshActor.h"
#include "Weapon.h"
#include "Relic.h"
#include "AttackSkill.h"

class Character : public MeshActor
{
	string name;
	int life;
	int lifeMax;
	int speed;
	Weapon* weapon;
	Relic* relic;
	bool isFrenzied;
	AttackSkill* attackSkill;
	//int fame; //LATER

public:
	Character(const RectangleShapeData& _data, const string& _name = "Character");

public:
	virtual void Attack(const int _amount);
	virtual void Defend();

};

