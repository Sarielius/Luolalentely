#ifndef GAMEPLAYSTATE_H
#define GAMEPLAYSTATE_H
#include "GameState.h"

class GameplayState :public GameState
{
public:
	GameplayState();
	~GameplayState();
	void update();
	void draw();

};
#endif