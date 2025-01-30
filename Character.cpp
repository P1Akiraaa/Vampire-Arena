#include "Character.h"
#include "TimerManager.h"
#include "AudioManager.h"

Character::Character(const Character& _other) : MeshActor(_other)
{
	animation = CreateComponent<AnimationComponent>();
}

Character::Character(const RectangleShapeData& _data, const CharacterData& _characterData)
	: MeshActor(_data, "Player") // TODO change
{
	characterData = _characterData;

	animation = CreateComponent<AnimationComponent>();
}

Character::Character(const float _radius, const CharacterData& _characterData)
	: MeshActor(_radius, 30, "Player") // TODO Remove
{
	characterData = _characterData;

	animation = CreateComponent<AnimationComponent>();
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

	const float _timeBetween = 0.1f;
	const Vector2i& _spriteSize = Vector2i(50, 53);
	const vector<SpriteData>& _spritesData =
	{
		{ _timeBetween, Vector2i(0, 0), _spriteSize },
		{ _timeBetween, Vector2i(65, 0), _spriteSize },
		{ _timeBetween, Vector2i(128, 0), _spriteSize },
		{ _timeBetween, Vector2i(192, 0), _spriteSize },
		{ _timeBetween, Vector2i(259, 0), _spriteSize },
	};

	const AnimationData& _animationData = AnimationData(2.0f, _spritesData);

	animation->AddAnimation(new Animation("Default", GetMesh()->GetShape(), _animationData));
	animation->SetCurrentAnimation("Default");
	animation->StartAnimation();
}

void Character::Deconstruct()
{
	Super::Deconstruct();
}

void Character::StartAnim()
{
	animation->StartAnimation();
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
