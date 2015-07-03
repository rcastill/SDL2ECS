#include "input.h"

Input::Input() : pumpedThisUpdate(false)
{
}

Input::~Input()
{
	delete[] keydownState;
}

void Input::Init()
{
	keyboardState = SDL_GetKeyboardState(&numKeys);
	keydownState = new bool[numKeys];

	for (unsigned int i = 0; i < numKeys; i++)
		keydownState[i] = false;	
}

void Input::PollEvents()
{
	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_KEYDOWN) {
			SDL_Scancode scancode = SDL_GetScancodeFromKey(event.key.keysym.sym);
			keydownReset.push_back(scancode);
			keydownState[scancode] = true;
		}
	}
}

bool Input::GetKeyDown(SDL_Keycode key)
{
	SDL_Scancode scancode = SDL_GetScancodeFromKey(key);
	return keydownState[scancode];
}

bool Input::GetKeyPressed(SDL_Keycode key)
{
	if (!pumpedThisUpdate) {
		pumpedThisUpdate = true;
		SDL_PumpEvents();
	}

	SDL_Scancode scancode = SDL_GetScancodeFromKey(key);
	return keyboardState[scancode];
}

void Input::Reset()
{
	for (unsigned int i = 0; i < keydownReset.size(); i++)
		keydownState[keydownReset[i]] = false;

	keydownReset.clear();
	pumpedThisUpdate = false;
}