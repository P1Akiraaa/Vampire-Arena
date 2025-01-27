#include "Entity.h"

Entity::Entity(const string& _name, const int _life, const int _speed, const bool _isFrenzied)
{
	name = _name;
	life = _life;
	speed = _speed;
}