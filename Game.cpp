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
    MeshActor* _backGround = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(1920.0f, 1080.0f), "background", JPG)));
    VerticalBox _buttons = VerticalBox(100.0f, 105.0f, 55, 3, { 550.0f, 800.0f });
    MeshActor* _mainBox = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(1000.0f, 800.0f), "Borders", JPG)));
    _mainBox->SetPosition(Vector2f(800.0f, 105.0f));
    HorizontalBox _itemBoxes = HorizontalBox(1274.0f, 200.0f, 20, 3, { 400.0f, 100.0f });
    HorizontalBox _otherBoxes = HorizontalBox(1274.0f, 707.0f, 20, 2, { 400.0f, 100.0f });

    MeshActor* _descriptionBox = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(400.0f, 360.0f), "OtherBorder")));
    MeshActor* _charaBox = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(250.0f, 240.0f), "OtherBorder")));
    MeshActor* _playerLifeBox = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(250.0f, 50.0f), "HealthBar")));
    MeshActor* _skillDescriptionBox = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(250.0f, 240.0f), "OtherBorder")));
    MeshActor* _skillBox = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(125.0f, 100.0f), "OtherBorder")));
    _descriptionBox->SetPosition(Vector2f(1274.0f, 300.0f));
    _charaBox->SetPosition(Vector2f(918.0f, 200.0f));
    _playerLifeBox->SetPosition(Vector2f(918.0f, 440.0f));
    _skillDescriptionBox->SetPosition(Vector2f(918.0f, 567.0f));
    _skillBox->SetPosition(Vector2f(918.0f, 567.0f));
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