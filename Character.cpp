#include "Character.h"

Character::Character(const RectangleShapeData& _data, const string& _name) : MeshActor(_data, _name)
{
	name = "Unknown";
	life = 100;
	lifeMax = 100;
	speed = 1;
	weapon = nullptr;
	relic = nullptr;
	isFrenzied = false;
	attackSkill = nullptr;
	//fame = 0;
}

void Character::Attack(const int _amount)
{
	//TODO Attack
}

void Character::Defend()
{
	//TODO Defend
}
