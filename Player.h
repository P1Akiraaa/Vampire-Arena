#pragma once
#include "Character.h"

class Player : public Character
{
public:
	Player(const RectangleShapeData& _data, const CharacterData& _characterData);
public:
	virtual void Construct() override;
};

