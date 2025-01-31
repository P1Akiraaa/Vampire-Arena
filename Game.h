#pragma once
#include "CoreMinimal.h"
#include "MouseActor.h"

using namespace UI;

class Game
{
protected:
	RenderWindow window;
	//MouseActor* MouseCursor;

public:
	FORCEINLINE virtual bool IsOver() const
	{
		return !window.isOpen();
	}

public:
	Game();
	virtual ~Game() {};

public:
	virtual void Start();
	virtual bool Update();
	void UpdateWindow();
	virtual void Stop();
};