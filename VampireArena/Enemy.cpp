#include "Enemy.h"

Enemy::Enemy(const RectangleShapeData& _data, const string& _name) : Character(_data, _name)
{
	goldToDrop = 0;
}

void Enemy::Attack(const int _amount)
{
	Super::Attack(_amount);
}

void Enemy::Defend()
{
	Super::Defend();
}