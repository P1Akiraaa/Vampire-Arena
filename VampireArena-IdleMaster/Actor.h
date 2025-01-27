#pragma once
#include "CoreMinimal.h"

struct TransformData
{
	Vector2f origin;
	Vector2f position;
	Angle rotation;
	Vector2f scale;
};


class Actor
{
	TransformData transform;

public:
	FORCEINLINE virtual bool IsValid(Actor* _actor) const
	{
		return _actor;
	}
	FORCEINLINE TransformData GetTransform() const
	{
		return transform;
	}
	FORCEINLINE Vector2f GetPosition() const
	{
		return transform.position;
	}
	FORCEINLINE Vector2f GetOrigin() const
	{
		return transform.origin;
	}
	FORCEINLINE Angle GetRotation() const
	{
		return transform.rotation;
	}
	FORCEINLINE Vector2f GetScale() const
	{
		return transform.scale;
	}
	FORCEINLINE virtual Drawable* GetDrawable() const = 0;

	//Setters
	FORCEINLINE virtual void SetPosition(const Vector2f& _position)
	{
		transform.position = _position;
	}
	FORCEINLINE virtual void SetOrigin(const Vector2f& _origin)
	{
		transform.origin = _origin;
	}
	FORCEINLINE virtual void SetRotation(const Angle& _rotation)
	{
		transform.rotation = _rotation;
	}
	FORCEINLINE virtual void SetScale(const Vector2f& _scale)
	{
		transform.scale = _scale;
	}
	FORCEINLINE virtual void SetTrasnform(const TransformData& _transformData)
	{
		transform = _transformData;
	}
	FORCEINLINE virtual void Move(const Vector2f& _offset)
	{
		transform.position += _offset;
		cout << transform.position.x << endl;
	}
	FORCEINLINE virtual void Rotate(const Angle& _angle)
	{
		transform.rotation += _angle;
	}
	FORCEINLINE virtual void Scale(const Vector2f& _factor)
	{
		transform.scale += _factor;
	}
public:
	virtual ~Actor() {};

public:

	template <typename T>
	T Cast(Actor* _actor)
	{
		if (!IsValid(_actor)) return nullptr;
		return dynamic_cast<T>(_actor);
	}
};