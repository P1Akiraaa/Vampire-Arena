#pragma once
#include "Component.h"

class LifeComponent : public Component
{
	u_int currentLife;
	u_int maxlife;
	bool isAlived;

public:

	FORCEINLINE bool IsAlived() const
	{
		return isAlived;
	}

	FORCEINLINE u_int GetCurrentLife() const
	{
		return currentLife;
	}

	void DescreaseCurrentLife(const u_int& _damage);

	void CheckIsAlived();

	LifeComponent(Actor* _owner, const u_int& _maxLife);
	LifeComponent(Actor* _owner, const LifeComponent* _other);
};