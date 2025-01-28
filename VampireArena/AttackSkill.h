#pragma once
#include "Macro.h"

class AttackSkill
{
	string name;
	string description;

public:
	FORCEINLINE string GetName() const
	{
		return name;
	}
	FORCEINLINE string GetDescription() const
	{
		return description;
	}

public:
	AttackSkill() = default;
	AttackSkill(const string& _name, const string& _description);

private:
	void ApplySkillEffect()
	{
		//TODO
	}
};