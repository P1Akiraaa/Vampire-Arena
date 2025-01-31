#include "Widget.h"
#include "CameraManager.h"
#include "HUD.h"
	

using namespace Camera;

UI::Widget::Widget(const string& _name, const RenderType& _type) : Actor(_name)
{
	type = _type;
	visibility = Visible;
	renderToken = 0;
	zOrder = 0; // pas de constructeur surcharg� pour le z Order pour un probl�me de construct
}

UI::Widget::~Widget()
{
}

void UI::Widget::Construct()
{
	const RenderData& _data = RenderData(bind(&Widget::Render, this, _1), type);
	renderToken = M_CAMERA.BindOnRenderWindow(_data, zOrder);
}

void UI::Widget::Deconstruct()
{
	M_CAMERA.UnbindOnRenderWindow(renderToken);
}