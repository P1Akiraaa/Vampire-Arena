#include "ShapeActor.h"
#include "TextureManager.h"

ShapeActor::ShapeActor(const float _radius, const string& _path, const IntRect _rect, const size_t& _pointsCount)
{
	shape = new CircleShape(_radius, _pointsCount);
	M_TEXTURE.Load(this, _path, _rect);
}

ShapeActor::ShapeActor(const Vector2f& _size, const string& _path, const IntRect& _rect)
{
	shape = new RectangleShape(_size);
	M_TEXTURE.Load(this, _path, _rect);
}

ShapeActor::~ShapeActor()
{
	delete shape;
}
