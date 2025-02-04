#include "VampireArena.h"
#include "Label.h"
#include "HUD.h"
#include "HorizontalBox.h"
#include "VerticalBox.h"
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

	Label* _label = M_HUD.CreateWidget<Label>("Vampire Arena", World);
	_label->SetZOrder(1);
	M_HUD.AddToViewport(_label);

    MeshActor* _background = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(1920.0f, 1080.0f), "background", JPG)));
    InitButton();
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

void VampireArena::InitButton()
{
    // TODO Change by Widget
    VerticalBox _buttons = VerticalBox(100.0f, 105.0f, 55, 3, "Button", { 550.0f, 800.0f });
    MeshActor* _mainBox = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(1000.0f, 800.0f), "Borders", JPG)));
    _mainBox->SetPosition(Vector2f(800.0f, 105.0f));
    HorizontalBox _itemBoxes = HorizontalBox(1274.0f, 200.0f, 20, 3, "OtherBorder", { 400.0f, 100.0f });
    HorizontalBox _otherBoxes = HorizontalBox(1274.0f, 707.0f, 20, 2, "OtherBorder", { 400.0f, 100.0f });

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
}