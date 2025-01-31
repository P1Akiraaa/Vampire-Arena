#pragma once
#include "CoreMinimal.h"
#include "Label.h"

using namespace UI;

class Boxes
{
	float posX;
	float posY;
	float spacing;
	u_int marging;
	u_int count;
	Vector2f size;

public:
	Boxes() = default;
	Boxes(float _posX, const float _posY, const u_int& _marging, const u_int& _count, const Vector2f& _size);

public:
	u_int ComputeHorizontalSpacing(float _sizeX, const u_int& _count, const Vector2f& _size);
	u_int ComputeVerticalSpacing(float _sizeY, const u_int& _count, const Vector2f& _size);
};