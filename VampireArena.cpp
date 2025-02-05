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
	InitWidget();
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
    //TODO new menu
	HorizontalBox* _box = M_HUD.CreateWidget<HorizontalBox>(BoxData(0, Vector2f(600.0f, 400.0f)));
	Label* _label = M_HUD.CreateWidget<Label>("test", World, "Bloody_Gothic_Empire", TTF);
	_box->SetZOrder(1);
	M_HUD.AddToViewport(_box);
	_label->SetZOrder(2);
	_box->AddWidget(_label);
	_box->SetPosition(Vector2f(500.0f, 500.0f));
    /*MeshActor* _mainBox = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(500.0f, 800.0f), "Character_Sheet")));
    _mainBox->SetPosition(Vector2f(350.0f, 100.0f));*/
}

void VampireArena::InitBackground()
{
	//MeshActor* _background = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(1960.0f, 1080.0f), "MainMenu_Background")));
}

void VampireArena::InitWidget()
{
	Label* _label = M_HUD.CreateWidget<Label>("Vampire Arena", World, "Bloody_Gothic_Empire", TTF);
	_label->SetZOrder(1);
	M_HUD.AddToViewport(_label);
}