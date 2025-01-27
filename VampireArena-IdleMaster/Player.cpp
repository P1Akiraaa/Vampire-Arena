#include "Player.h"

Player::Player()
{

}

Player::Player(const string& _name, const int _life, const int _speed,
	const bool _isFrenzied, const int _gold) : Entity(_name, _life, _speed, _isFrenzied)
{
	gold = _gold;
}