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
	//InitWidget();
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
	HorizontalBox* _box1 = M_HUD.CreateWidget<HorizontalBox>(BoxData(Vector2f(500.0f, 20.0f)));
	HorizontalBox* _box2 = M_HUD.CreateWidget<HorizontalBox>(BoxData(Vector2f(500.0f, 20.0f), 10.0f));
	HorizontalBox* _box3 = M_HUD.CreateWidget<HorizontalBox>(BoxData(Vector2f(500.0f, 20.0f), 10.0f));
	VerticalBox* _box4 = M_HUD.CreateWidget<VerticalBox>(BoxData(Vector2f(200.0f, 600.0f), 0.0f));
	_box4->SetPosition(Vector2f(0.0f, 250.0f));
	Label* _label = M_HUD.CreateWidget<Label>("test", World, "Bloody_Gothic_Empire", TTF);
	Label* _label2 = M_HUD.CreateWidget<Label>("test2", World, "Bloody_Gothic_Empire", TTF);
	Label* _label3 = M_HUD.CreateWidget<Label>("test3", World, "Bloody_Gothic_Empire", TTF);
	Label* _label4 = M_HUD.CreateWidget<Label>("test4", World, "Bloody_Gothic_Empire", TTF);
	Label* _label5 = M_HUD.CreateWidget<Label>("test5", World, "Bloody_Gothic_Empire", TTF);
	Label* _label6 = M_HUD.CreateWidget<Label>("test6", World, "Bloody_Gothic_Empire", TTF);
	_label2->SetZOrder(1);
	_label->SetZOrder(1);
	_box1->AddWidget(_label);
	_box1->AddWidget(_label2);
	/*_box2->AddWidget(_label3);
	_box2->AddWidget(_label4);
	_box3->AddWidget(_label5);
	_box3->AddWidget(_label6);
	_box4->AddWidget(_box1);
	_box4->AddWidget(_box2);
	_box4->AddWidget(_box3);*/
	/*MeshActor* _mainBox = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(500.0f, 800.0f), "Character_Sheet")));
	_mainBox->SetPosition(Vector2f(350.0f, 100.0f));*/
}

void VampireArena::InitBackground()
{
	MeshActor* _background = Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(1960.0f, 1080.0f), "MainMenu_Background")));
}

void VampireArena::InitWidget()
{
	Label* _label = M_HUD.CreateWidget<Label>("Vampire Arena", World, "Bloody_Gothic_Empire", TTF);
	_label->SetZOrder(1);
	M_HUD.AddToViewport(_label);
}