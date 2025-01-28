#pragma once
#include "Widget.h"
#include "ShapeObject.h"
namespace UI
{
	class Button : public Widget
	{
		function<void()> callBack;
		ShapeObject* shape;

	public:
		Button(const function<void()> _callback, const Vector2f& _coordinate = Vector2f(),
			const Vector2f& _size = {10.0f, 10.0f});
		~Button();

	private:
		void InitShape(const Vector2f& _coordinate);
		void Interact() const;
	public:
		virtual void Render(RenderWindow& _window) ;
	};





}


