#pragma once
#include "Box.h"

class HorizontalBox : public Box
{
	
public:
	HorizontalBox(const BoxData& _data);

public:
	void CreateHorizontalBox(const BoxData& _data);
};