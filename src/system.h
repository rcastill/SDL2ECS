#ifndef SYSTEM_H
#define SYSTEM_H

#include "game.h"

class System
{
private:
	Game *game;

protected:
	bool setFailure = false;
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