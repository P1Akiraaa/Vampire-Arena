#include "VampireArena.h"
#include "Label.h"
#include "HUD.h"

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