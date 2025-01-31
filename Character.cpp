#include "Character.h"

Character::Character(const RectangleShapeData& _data, const CharacterData& _characterData)
	: MeshActor(_data, _characterData.name)
{
	characterData = _characterData;
}

Character::~Character()
{

}

void Character::Attack(const u_int _amount)
{
	//TODO Attack
}

void Character::Defend()
{
	//TODO Defend
}

CharacterData::CharacterData(const string& _name, const u_int _gold, const u_int _fame, 
	const u_int _life, const u_int _lifeMax, const bool _isFrienzied,
	Weapon* _weapon, Armor* _armor, Relic* _relic, AttackSkill* _attackSkill)
{
	name = _name;
	gold = _gold;
	fame = _fame;
	life = _life;
	lifeMax = _lifeMax;
	isFrenzied = _isFrienzied;
	weapon = _weapon;
	armor = _armor;
	relic = _relic;
	_attackSkill = _attackSkill;
}
