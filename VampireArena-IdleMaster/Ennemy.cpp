#include "Ennemy.h"

Ennemy::Ennemy()
{

}

Ennemy::Ennemy(const string& _name, const int _life, const int _speed, const int _golToDrop,
			   const bool _isFrenzied) : Entity(_name, _life, _speed, _isFrenzied)
{
	goldToDrop = _golToDrop;
}