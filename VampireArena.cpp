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

	InitBackground();
	InitMenu();   
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

void VampireArena::InitMenu()
{
    //TODO new menu
	HorizontalBox* _box1 = M_HUD.CreateWidget<HorizontalBox>(BoxData(Vector2f(600.0f, 200.0f), 0.0f));
}

void VampireArena::InitBackground()
{
	MeshActor* _background = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(1960.0f, 1080.0f), "MainMenu_Background")));
}