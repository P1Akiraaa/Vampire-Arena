#include "ShapeObject.h"
#include "TextureManager.h"

ShapeObject::ShapeObject(const CircleShapeData& _data)
{
	objectData = ShapeObjectData(SOT_CIRCLE, _data);
	InitCircle(*objectData.data.circleData);
}

ShapeObject::ShapeObject(const RectangleShapeData& _data)
{
	objectData = ShapeObjectData(SOT_RECTANGLE, _data);
	InitRectangle(*objectData.data.rectangleData);
}

ShapeObject::ShapeObject(const ShapeObject& _other)
{
	objectData = _other.objectData;

	if (objectData.type == SOT_CIRCLE)
	{
		InitCircle(*objectData.data.circleData);
	}

	else if (objectData.type == SOT_RECTANGLE)
	{
		InitRectangle(*objectData.data.rectangleData);
	}
}

ShapeObject::~ShapeObject()
{
	delete shape;
}


void ShapeObject::InitCircle(const CircleShapeData& _data)
{
	shape = new CircleShape(_data.radius, _data.pointCount);
	M_TEXTURE.Load(this, _data.path, _data.rect);
}

void ShapeObject::InitRectangle(const RectangleShapeData& _data)
{
	shape = new RectangleShape(_data.size);
	M_TEXTURE.Load(this, _data.path, _data.rect, _data.textureType, _data.isRepeated);
}