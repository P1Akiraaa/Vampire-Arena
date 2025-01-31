#include "MouseActor.h"

MouseActor::MouseActor(const float _radius, const size_t& _pointCount, const string& _path
	, const IntRect& _rect, const string& _name)
	: MeshActor(_radius, _pointCount, _path, _rect, _name)
{

}

void MouseActor::Tick(const float _deltaTime)
{
	SetPosition(Vector2f(Mouse::getPosition().x - 2, Mouse::getPosition().y - 20.0f));
}
