#include "VampireArena.h"
#include "Label.h"
#include "HUD.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "SoundSample.h"

using namespace UI;
using namespace Input;

VampireArena::VampireArena() : Game()
{
}

VampireArena::~VampireArena()
{
}

void VampireArena::Start()
{
	Super::Start();
	

	M_INPUT.BindAction([&]() { 
		new SoundSample("hugooo");
		M_AUDIO.PlaySample<SoundSample>("hugooo", MP3);  }, Clicked::Left);

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
