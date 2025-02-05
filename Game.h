#pragma once
#include "CoreMinimal.h"
#include "HorizontalBox.h"
#include "VerticalBox.h"

class Game
{
protected:
	RenderWindow window;

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