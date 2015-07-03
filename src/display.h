#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include "system.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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

	~Display();

	void Init();

	SDL_Window *GetSDLWindow();

	string GetTitle();
	int GetWidth();
	int GetHeight();
};

#endif