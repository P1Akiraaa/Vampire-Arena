#include "Game.h"
#include "ActorManager.h"
#include "CameraManager.h"
#include "TimerManager.h"

#include "MeshActor.h"

Game::Game()
{
	window = RenderWindow();
}


void Game::Start()
{
    window.create(VideoMode({ 1270, 720 }), "Vampire Arena");

    Level::SpawnActor(MeshActor(RectangleShapeData(CAST(Vector2f, window.getSize()), "Background", PNG)));
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