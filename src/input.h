#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include <vector>
#include "system.h"

using namespace std;

class Input : public System
{
private:
	SDL_Event event;

	int numKeys;

	bool pumpedThisUpdate;
	const Uint8 *keyboardState;

	vector<SDL_Scancode> keydownReset;
	bool *keydownState;

public:
	Input();
	~Input();

	void Init();

	void PollEvents();

	bool GetKeyDown(SDL_Keycode key);
	bool GetKeyPressed(SDL_Keycode key);

	void Reset();
};


#endif