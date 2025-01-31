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

void Character::RenderMesh(RenderWindow& _window)
{
	Super::RenderMesh(_window);
}

void Character::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);
}

void Character::Construct()
{
	Super::Construct();
}

void Character::Deconstruct()
{
	Super::Deconstruct();
}

void Character::StartAnim()
{
	characterData.animation->StartAnimation();
}

CharacterData::CharacterData(const string& _name, const u_int _gold, const u_int _fame, 
	const u_int _life, const u_int _lifeMax, const bool _isFrienzied,
	Weapon* _weapon, Armor* _armor, Relic* _relic, AttackSkill* _attackSkill, AnimationComponent* _animation)
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
	attackSkill = _attackSkill;
	animation = _animation;
}