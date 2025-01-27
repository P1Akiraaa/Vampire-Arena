#pragma once
#include "Actor.h"

class TextActor : public Actor
{
	Text* text;

public:
	Drawable* GetDrawable() const
	{
		return text;
	}

	FORCEINLINE virtual void SetPosition(const Vector2f& _position)
	{
		SUPER::SetPosition(_position);
		text->setPosition(_position);
	}
	FORCEINLINE virtual void SetOrigin(const Vector2f& _origin)
	{
		SUPER::SetOrigin(_origin);
		text->setOrigin(_origin);
	}
	FORCEINLINE virtual void SetRotation(const Angle& _rotation)
	{
		SUPER::SetRotation(_rotation);
		text->setRotation(_rotation);
	}
	FORCEINLINE virtual void SetScale(const Vector2f& _scale)
	{
		SUPER::SetScale(_scale);
		text->setScale(_scale);
	}
	FORCEINLINE virtual void SetTrasnform(const TransformData& _transformData)
	{
		SUPER::SetTrasnform(_transformData);
		text->setOrigin(_transformData.origin);
		text->setPosition(_transformData.position);
		text->setRotation(_transformData.rotation);
		text->setScale(_transformData.scale);
	}

	TextActor(string _font, string _text, u_int _charSize = 30U);

	~TextActor();
};

