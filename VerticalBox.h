#pragma once
#include "Box.h"

class VerticalBox : public Box
{

public:
	VerticalBox(const BoxData& _data);

public:
	void CreateVerticalBox(const BoxData& _data);
};

