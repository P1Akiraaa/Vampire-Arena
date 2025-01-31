#include "LifeComponent.h"

void LifeComponent::DescreaseCurrentLife(const u_int& _damage)
{
	currentLife = currentLife - _damage > 0 ? currentLife - _damage : 0;
}

void LifeComponent::CheckIsAlived()
{
	isAlived = currentLife > 0;
}

LifeComponent::LifeComponent(Actor* _owner, const u_int& _maxLife) : Component(_owner)
{
	maxlife = _maxLife;
	currentLife = _maxLife;
	CheckIsAlived();
}

LifeComponent::LifeComponent(Actor* _owner, const LifeComponent* _other) : Component(_owner)
{
	maxlife = _other->maxlife;
	currentLife = _other->currentLife;
	isAlived = _other->isAlived;
}
