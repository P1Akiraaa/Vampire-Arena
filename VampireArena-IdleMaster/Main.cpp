#include "ShapeActor.h"

int main()
{
	RenderWindow _window(VideoMode({ 500, 500 }), "SFML");
	ShapeActor _shape = ShapeActor(250.0f, "Pierre.png");

	while (_window.isOpen())
	{
		while (const optional _event = _window.pollEvent())
		{
			if (_event->is<Event::Closed>())
			{
				_window.close();
			}
		}

		_window.clear();
		_window.draw(*_shape.GetDrawable());
		_window.display();
	}

	return EXIT_SUCCESS;
}