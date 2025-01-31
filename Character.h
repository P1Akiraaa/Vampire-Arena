#pragma once
#include "MeshActor.h"
#include "Weapon.h"
#include "Relic.h"
#include "Armor.h"
#include "AttackSkill.h"
#include "AnimationComponent.h"
#include "LifeComponent.h"

struct CharacterData
{
	string name;
	u_int gold = 0;
	u_int fame = 0;
	u_int speed = 0;
	bool isFrenzied = false;
	Weapon* weapon = nullptr;
	Armor* armor = nullptr;
	Relic* relic = nullptr;
	AttackSkill* attackSkill = nullptr;

	CharacterData() = default;
	CharacterData(const string& _name, const u_int _gold = 0, const u_int _fame = 0,
		const bool _isFrienzied = false, Weapon* _weapon = nullptr, Armor* _armor = nullptr, Relic* _relic = nullptr, AttackSkill* _attackSkill = nullptr);
};

class Character : public MeshActor
{
	CharacterData characterData;
	AnimationComponent* animation;
	LifeComponent* lifeComponent;

public:

	#pragma region Getters

	FORCEINLINE CharacterData GetCharacterData() const
	{
		return characterData;
	}
	FORCEINLINE void SetCharacterData(const CharacterData& _characterData) 
	{
		characterData = _characterData;
	}

	#pragma region Gold

		FORCEINLINE u_int GetGold() const
		{
			return characterData.gold;
		}
		FORCEINLINE void SetGold(const u_int& _gold)
		{
			characterData.gold = _gold;
		}
		FORCEINLINE void AddGold(const u_int& _amount)
		{
			characterData.gold += _amount;
		}
		FORCEINLINE void RemoveGold(const u_int& _amount)
		{
			characterData.gold = (characterData.gold - _amount < 0 ? 0 : characterData.gold - _amount);
		}

	#pragma endregion

	#pragma region Fame

		FORCEINLINE u_int GetFame() const
		{
			return characterData.fame;
		}
		FORCEINLINE void SetFame(const u_int& _fame)
		{
			characterData.fame = _fame;
		}
		FORCEINLINE void AddFame(const u_int& _amount)
		{
			characterData.fame += _amount;
		}
		FORCEINLINE void RemoveFame(const u_int& _amount)
		{
			characterData.fame = (characterData.fame - _amount < 0 ? 0 : characterData.fame - _amount);
		}

	#pragma endregion

	#pragma endregion

public:
	Character() = default;
	Character(const RectangleShapeData& _data, const CharacterData& _characterData);
	~Character();
public:
	void Attack(const u_int _amount);
	void Defend();

	virtual void RenderMesh(RenderWindow& _window);
	virtual void Tick(const float _deltaTime) override;
	virtual void Construct() override;
	virtual void Deconstruct() override;
	void StartAnim();
};