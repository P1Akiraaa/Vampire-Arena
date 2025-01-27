#include "Game.h"
#include "GameManager.h"

void InitConfig()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    Logger::Reset();
}

int main()
{
    InitConfig();
    Game* _game = new Game();
    M_GAME.Launch(_game);

	return EXIT_SUCCESS;
}