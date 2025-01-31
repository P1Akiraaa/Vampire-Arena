#pragma once
#include "MeshActor.h"
#include "Widget.h"

using namespace UI;
class MouseActor : public Widget
{
	MeshActor* cursor;
public:
	//TODO Rectangle
	MouseActor(const float _radius, const size_t& _pointCount = 30, const string& _path = ""
			  ,const IntRect& _rect = {}, const string& _name = "MouseActor", const RenderType& _type = Screen);

	virtual void Tick(const float _deltaTime) override;
};

