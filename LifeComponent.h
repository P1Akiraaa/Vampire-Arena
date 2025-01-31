#pragma once
#include "Component.h"

class LifeComponent : public Component
{
	u_int currentLife;
	u_int maxlife = 100;
	bool isAlive;

public:

	FORCEINLINE bool IsAlive() const
	{
		return isAlive;
	}

	FORCEINLINE u_int GetCurrentLife() const
	{
		return currentLife;
	}

	void DescreaseCurrentLife(const u_int& _damage);

	void CheckIsAlive();

	LifeComponent(Actor* _owner, const u_int& _maxLife);
	LifeComponent(Actor* _owner, const LifeComponent* _other);
};

