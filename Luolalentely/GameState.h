#ifndef GAMESTATE_H
#define GAMESTATE_H
class GameState
{
public:
	GameState();
	~GameState();
	virtual void update() = 0;
	virtual void draw() = 0;
};
#endif
