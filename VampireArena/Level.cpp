#include "Level.h"

Level::Level(const string& _title, const vector<ShapeObject*>& _shapes, const string& _description)
{
	title = _title;
	description = _description;
	shapes = _shapes;
}

Level::~Level()
{
	for (auto _shape : shapes)
	{
		delete _shape;
	}
}