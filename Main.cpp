#include "VampireArena.h"
#include "GameManager.h"
#include <memory>

void InitConfig()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    Logger::Reset();
}

int main()
{
    InitConfig();
    M_GAME.Launch(new VampireArena());

    /*class Data
    {
        string name = "Data";
        int value = 0;

    public:
        Data(const string& _name, const int _value = -1) : name(_name), value(_value) {}

        void Print()
        {
            LOG(Display, name + " => " + to_string(value));
        }
    };
    unique_ptr _uniquePtr = make_unique<Data>("Data");
    unique_ptr _uniquePtr2 = move(_uniquePtr);
    shared_ptr _sharedPtr = make_shared<Data>("Data2");
    weak_ptr _weakPtr = _sharedPtr;
    cout << _sharedPtr << endl;
    _sharedPtr = nullptr;
    cout << _weakPtr.lock() << endl;*/

    /*RenderWindow _window(VideoMode({ 800, 600 }), "SFML Works !");

    const Vector2f& _size = Vector2f(200.0f, 50.0f);
    const Vector2f& _position = Vector2f(_window.getSize()) / 2.0f - _size / 2.0f;

    const vector<Vertex>& _vertices =
    {
        { Vector2f(_position.x, _position.y), Color::Red},
        { Vector2f(_position.x + _size.x, _position.y), Color::Blue },
        { Vector2f(_position.x + _size.x, _position.y + _size.y), Color::Green},
        { Vector2f(_position.x, _position.y + _size.y), Color::Yellow },
        { Vector2f(_position.x, _position.y), Color::Red},
        { Vector2f(_position.x + _size.x, _position.y + _size.y), Color::Blue},
        { Vector2f(_position.x + _size.x, _position.y), Color::Green },
        { Vector2f(_position.x, _position.y + _size.y), Color::Yellow },
    };

    while (_window.isOpen())
    {
        while (const optional _event = _window.pollEvent())
        {
            if (_event->is<Event::Closed>())
            {
                _window.close();
            }

            if (const Event::Resized* _resized = _event->getIf<Event::Resized>())
            {
                const int _newX = _resized->size.x <= (int)(_position.x + _size.x) ? (int)(_position.x + _size.x) : _resized->size.x;
                const int _newY = _resized->size.y <= (int)(_position.y + _size.y) ? (int)(_position.y + _size.y) : _resized->size.y;
                _window.setSize(Vector2u(_newX, _newY));
            }
        }

        _window.clear(Color::White);
        _window.draw(_vertices.data(), _vertices.size(), PrimitiveType::TriangleStrip);
        _window.display();
    }*/

    return EXIT_SUCCESS;
}