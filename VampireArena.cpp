#include "VampireArena.h"
#include "Label.h"
#include "HUD.h"

#include "ActorManager.h"
#include "CameraManager.h"
#include "TimerManager.h"
#include"CombatLevel.h"

using namespace UI;

VampireArena::VampireArena() : Game()
{
}

VampireArena::~VampireArena()
{
}

void VampireArena::Start()
{
	Super::Start();


	Label* _label = M_HUD.CreateWidget<Label>("Vampire Areana", World);
	_label->SetZOrder(1);
	M_HUD.AddToViewport(_label);

    MeshActor* _backGround = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(1920.0f, 1080.0f), "background", JPG)));
    // TODO remove
    const float _sideStartX = 100.0f;
    float _sideStartY = 105.0f;
    const Vector2f& _sideSize = Vector2f(550.0f, 180.0f);
    const float _sideSpacing = 800 / 3 - _sideSize.y;
    for (u_int _index = 0; _index < 3; _index++)
    {
        MeshActor* _sideButton = Level::SpawnActor(MeshActor(RectangleShapeData(_sideSize, "Default")));
        _sideButton->SetPosition(Vector2f(_sideStartX, _sideStartY));
        _sideStartY += _sideSize.y + _sideSpacing;
    }

    MeshActor* _mainBox = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(1000.0f, 800.0f), "Borders", JPG)));
    float _itemStartX = 1274.0f;
    const float _itemStartY = 200.0f;
    const Vector2f& _itemSize = Vector2f(120.0f, 100.0f);
    const float _itemSpacing = (400.0f - _itemSize.x * 3) / 2.0f;
    for (u_int _index = 0; _index < 3; _index++)
    {
        MeshActor* _itemBox = Level::SpawnActor(MeshActor(RectangleShapeData(_itemSize, "Floor")));
        _itemBox->SetPosition(Vector2f(_itemStartX, _itemStartY));
        _itemStartX += _itemSize.x + _itemSpacing;
    }

    float _laterStartX = 1274.0f;
    const float _laterStartY = 707.0f;
    const Vector2f& _laterSize = Vector2f(180.0f, 100.0f);
    const float _laterSpacing = (400.0f - _laterSize.x * 2);
    for (u_int _index = 0; _index < 2; _index++)
    {
        MeshActor* _laterBox = Level::SpawnActor(MeshActor(RectangleShapeData(_laterSize, "Paddle")));
        _laterBox->SetPosition(Vector2f(_laterStartX, _laterStartY));
        _laterStartX += _laterSize.x + _laterSpacing;
    }

    MeshActor* _descriptionBox = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(400.0f, 360.0f), "Paddle")));
    MeshActor* _charaBox = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(250.0f, 240.0f), "Floor")));
    MeshActor* _playerLifeBox = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(250.0f, 50.0f), "Paddle")));
    MeshActor* _skillDescriptionBox = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(250.0f, 240.0f), "Floor")));
    MeshActor* _skillBox = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(125.0f, 100.0f), "Paddle")));

    _mainBox->SetPosition(Vector2f(800.0f, 105.0f));

    _descriptionBox->SetPosition(Vector2f(1274.0f, 300.0f));
    _charaBox->SetPosition(Vector2f(918.0f, 200.0f));
    _playerLifeBox->SetPosition(Vector2f(918.0f, 440.0f));
    _skillDescriptionBox->SetPosition(Vector2f(918.0f, 567.0f));
    _skillBox->SetPosition(Vector2f(918.0f, 567.0f));

}

bool VampireArena::Update()
{
	Super::Update();
	return IsOver();
}

void VampireArena::UpdateWindow()
{
	Super::UpdateWindow();
}

void VampireArena::Stop()
{
	Super::Stop();
}
