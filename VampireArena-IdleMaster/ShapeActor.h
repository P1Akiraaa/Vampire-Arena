#pragma once
#include "Actor.h"

class ShapeActor : public Actor
{
	Shape* shape;
	Texture texture;

public:
	FORCEINLINE Texture& GetTexture()
	{
		return texture;
	}

	FORCEINLINE virtual Shape* GetDrawable() const
	{
		return shape;
	}

	FORCEINLINE virtual void SetPosition(const Vector2f& _position)
	{
		SUPER::SetPosition(_position);
		shape->setPosition(_position);
	}
	FORCEINLINE virtual void SetOrigin(const Vector2f& _origin)
	{
		SUPER::SetOrigin(_origin);
		shape->setOrigin(_origin);
	}
	FORCEINLINE virtual void SetRotation(const Angle& _rotation)
	{
		SUPER::SetRotation(_rotation);
		shape->setRotation(_rotation);
	}
	FORCEINLINE virtual void SetScale(const Vector2f& _scale)
	{
		SUPER::SetScale(_scale);
		shape->setScale(_scale);
	}
	FORCEINLINE virtual void SetTrasnform(const TransformData& _transformData)
	{
		SUPER::SetTrasnform(_transformData);
		shape->setOrigin(_transformData.origin);
		shape->setPosition(_transformData.position);
		shape->setRotation(_transformData.rotation);
		shape->setScale(_transformData.scale);
	}

	FORCEINLINE virtual void Move(const Vector2f& _offset)
	{
		SUPER::Move(_offset);
		shape->Transformable::move(_offset);
	}
	FORCEINLINE virtual void Rotate(const Angle& _angle)
	{
		SUPER::Rotate(_angle);
		shape->rotate(_angle);
	}
	FORCEINLINE virtual void Scale(const Vector2f& _factor)
	{
		SUPER::Scale(_factor);
		shape->scale(_factor);
	}

	// Circle
	ShapeActor(const float _radius, const string& _path = "", const IntRect _rect = IntRect(), const size_t& _pointsCount = 30);

	// Rectangle
	ShapeActor(const Vector2f& _size, const string& _path = "", const IntRect& _rect = IntRect());

	~ShapeActor();
};