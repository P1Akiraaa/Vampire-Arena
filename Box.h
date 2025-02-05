#pragma once
#include "CoreMinimal.h"
#include "Widget.h"

using namespace UI;

struct BoxData
{
	float spaceBetween;
	u_int elementCount;
	Vector2f startPosition;
	Vector2f size;

	BoxData()
	{
		spaceBetween = 0;
		elementCount = 1;
		startPosition = { 0.0f, 0.0f };
		size = { 0.0f, 0.0f };
	}

	BoxData(const float _spaceBetween, const u_int& _elementCount, Vector2f _startPosition,
			const Vector2f& _size)
	{
		spaceBetween = _spaceBetween;
		elementCount = _elementCount;
		startPosition = _startPosition;
		size = _size;
	}
};

class Box : public Widget
{
	BoxData data;

public:
	FORCEINLINE void AddWidget(Widget* _widget)
	{
		AddChild(_widget, AT_KEEP_RELATIVE);
	}
	FORCEINLINE void RemoveWidget(Widget* _widget)
	{
		RemoveChild(_widget);
	}

#pragma region Getters
	FORCEINLINE Vector2f GetStartPosition() const
	{
		return data.startPosition;
	}
	FORCEINLINE Vector2f GetSize() const
	{
		return data.size;
	}
	FORCEINLINE u_int GetElementCount() const
	{
		return data.elementCount;
	}
#pragma endregion

#pragma region Setters
	FORCEINLINE virtual void SetPosition(const Vector2f& _startPosition) override
	{
		Super::SetPosition(_startPosition);
		SetPosition(_startPosition);
	}
	FORCEINLINE virtual void SetScale(const Vector2f& _size) override
	{
		Super::SetScale(_size);
		SetScale(_size);
	}
	FORCEINLINE virtual void SetRotation(const Angle& _rotation) override
	{
		Super::SetRotation(_rotation);
		SetRotation(_rotation);
	}

	FORCEINLINE virtual void Move(const Vector2f& _offset) override
	{
		Super::Move(_offset);
		Move(_offset);
	}
	FORCEINLINE virtual void Scale(const Vector2f& _factor) override
	{
		Super::Scale(_factor);
		Scale(_factor);
	}
	FORCEINLINE virtual void Rotate(const Angle& _angle)
	{
		Super::Rotate(_angle);
		Rotate(_angle);
	}
#pragma endregion

public:
	Box() = default;
	Box(const BoxData& _data);
};