#pragma once
#include "Character.h"

class Enemy : public Character
{
public:
	Enemy(const RectangleShapeData& _data, const CharacterData& _characterData);
public:
	virtual void Construct() override;
};

