#pragma once
#include "MeshActor.h"

class MouseActor : public MeshActor
{
public:
	MouseActor(const float _radius, const size_t& _pointCount = 30, const string& _path = ""
			  ,const IntRect& _rect = {}, const string& _name = "MouseActor");

	virtual void Tick(const float _deltaTime) override;
};

