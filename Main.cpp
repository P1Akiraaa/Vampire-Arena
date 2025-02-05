#include "VampireArena.h"
#include "GameManager.h"
#include "CombatLevel.h"
#include <memory>

void InitConfig()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    Logger::Reset();
}

int main()
{
    InitConfig();
    /*RenderWindow _window = RenderWindow(VideoMode(Vector2u(1920, 1080)), "Vampire Arena");
    CircleShape _circle = CircleShape(50.0f, 30);
    _circle.setFillColor(Color::Green);
    _circle.setPosition(Vector2f(960.0f, 540.0f));
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
        _window.draw(_circle);
        _window.display();
    }*/

    M_GAME.Launch(new CombatLevel());

    return EXIT_SUCCESS;
}