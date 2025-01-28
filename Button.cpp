#include "Button.h"
#include "InputManager.h"
#include "GameManager.h"

UI::Button::Button(const function<void()> _callback, const Vector2f& _coordinate,
	const Vector2f& _size) 
	: Widget("Button")
{
	callBack = _callback;
	shape = new ShapeObject(_size);
	InitShape(_coordinate);

}
UI::Button::~Button()
{
	delete shape;
}

void UI::Button::InitShape(const Vector2f& _coordinate)
{
	shape->SetOrigin(shape->GetDrawable()->getGeometricCenter());
	shape->SetPosition(_coordinate);

	
}

void UI::Button::Interact() const
{
	callBack();
}

void UI::Button::Render(RenderWindow& _window)
{

}
