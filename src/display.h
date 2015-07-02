#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include "system.h"
#include <SDL2/SDL.h>

using namespace std;

class Display : public System
{
private:
	string title;
	int width;
	int height;

	SDL_Window *window;
	SDL_Surface *surface;

public:
	Display();
	Display(string title, int width, int height);
	Display(const Display& display);

	~Display();

	SDL_Window *GetSDLWindow();

	string GetTitle();
	int GetWidth();
	int GetHeight();

	Display &operator=(Display &&other);
};

#endif