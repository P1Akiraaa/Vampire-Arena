#include "Equipable.h"

Equipable::Equipable(const string _name, const string& _description, const int _upgradePrice, const RarityType _rarity, 
					 const int _equipableStat, const double _weight, const ElementType& _element, 
					 const bool _isSaboted) : Item(_name, _description, _upgradePrice, _rarity)
{
	equipableStat = _equipableStat;
	weight = _weight;
	element = _element;
	isSaboted = _isSaboted;
}