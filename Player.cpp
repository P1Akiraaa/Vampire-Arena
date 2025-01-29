#include "Player.h"

Player::Player(const RectangleShapeData& _data, const string& _name) : Character(_data, _name)
{
	gold = 0;
}

void Player::Attack(const int _amount)
{
	Super::Attack(_amount); // Peut-être il y en a pas besoin
	//TODO Attack
}

void Player::Defend()
{
	Super::Defend(); // Peut-être il y en a pas besoin
}