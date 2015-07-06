#ifndef SYSTEM_H
#define SYSTEM_H

class Game;

#include <iostream>

using namespace std;

class System
{
protected:
	Game *game;
	bool setFailure;
	string failureDetail;

	void PushError(string detail);

public:
	System();

	void SetGame(Game *game);
	
	virtual void Init();

	bool Check();
	string GetError();
};

#endif