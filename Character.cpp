#include "Character.h"

Character::Character(const RectangleShapeData& _data, const CharacterData& _characterData)
	: MeshActor(_data, _characterData.name)
{
	characterData = _characterData;
	animation = CreateComponent<AnimationComponent>();
	lifeComponent = CreateComponent<LifeComponent>(100);
}

CharacterData::CharacterData(const string& _name, const u_int& _gold, const u_int& _fame,
	const bool _isFrienzied,
	Weapon* _weapon, Armor* _armor, Relic* _relic, AttackSkill* _attackSkill)
{
	name = _name;
	gold = _gold;
	fame = _fame;
	isFrenzied = _isFrienzied;
	weapon = _weapon;
	armor = _armor;
	relic = _relic;
	attackSkill = _attackSkill;
}

Character::~Character()
{

}

int Character::Attack()
{
	return characterData.weapon->GetAttackValue();
}

int Character::Defend()
{
	return characterData.armor->GetResistance();
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
	//animation->StartAnimation();
}