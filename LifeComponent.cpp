#include "LifeComponent.h"

void LifeComponent::DescreaseCurrentLife(const u_int& _damage)
{
	currentLife = currentLife - _damage > 0 ? currentLife - _damage : 0;
}

void LifeComponent::CheckIsAlive()
{
	isAlive = currentLife > 0;
}

LifeComponent::LifeComponent(Actor* _owner, const u_int& _maxLife) : Component(_owner)
{
	maxlife = _maxLife;
	currentLife = _maxLife;
	CheckIsAlive();
}

LifeComponent::LifeComponent(Actor* _owner, const LifeComponent* _other) : Component(_owner)
{
	maxlife = _other->maxlife;
	currentLife = _other->currentLife;
	isAlive = _other->isAlive;
}
