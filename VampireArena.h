#pragma once
#include "Game.h"
class VampireArena :   public Game
{
public:
	VampireArena();
	~VampireArena();

public:
	virtual void Start();
	virtual bool Update();
	void UpdateWindow();
	virtual void Stop();

private:
	void InitButton();
};

