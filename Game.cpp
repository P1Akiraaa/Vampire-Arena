#include "Game.h"
#include "ActorManager.h"
#include "CameraManager.h"
#include "TimerManager.h"
#include"CombatLevel.h"

using namespace Camera;

Game::Game()
{
	window = RenderWindow();
}

void Game::Start()
{
    window.create(VideoMode({ 1920, 1080 }), "Vampire Arena");
    M_CAMERA.CreateCamera(Vector2f(960.0f, 540.0f), Vector2f(1920.0f, 1080.0f), "Widget");
    MeshActor* _bigShape = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(900.0f, 800.0f), "Default")));
    MeshActor* _littleShape = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(120.0f, 100.0f), "Floor")));
    MeshActor* _littleShape2 = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(120.0f, 100.0f), "Floor")));
    MeshActor* _littleShape3 = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(120.0f, 100.0f), "Floor")));
    _bigShape->SetPosition(Vector2f(800.0f, 105.0f));
    _littleShape->SetPosition(Vector2f(1215.0f, 140.0f));
    _littleShape2->SetPosition(Vector2f(1375.0f, 140.0f));
    _littleShape3->SetPosition(Vector2f(1535.0f, 140.0f));
};

bool Game::Update()
{
    TM_Seconds& _timer = M_TIMER;
    _timer.Update();

    while (const optional _event = window.pollEvent())
    {
        if (_event->is<Event::Closed>())
        {
            window.close();
        }
    }

    const float _deltaTime = _timer.GetDeltaTime().asSeconds();
    M_ACTOR.Tick(_deltaTime);

    return IsOver();
}

void Game::UpdateWindow()
{
    window.clear();
    M_CAMERA.RenderAllCameras(window);
    window.display();
}

void Game::Stop()
{
    M_ACTOR.BeginDestroy();
}