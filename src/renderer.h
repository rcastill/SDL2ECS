#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include "system.h"
#include "display.h"

#define DEFAULT_DRAW_COLOR_R 0xff
#define DEFAULT_DRAW_COLOR_G 0x00
#define DEFAULT_DRAW_COLOR_B 0x00
#define DEFAULT_DRAW_COLOR_A 0xff

class Renderer : public System
{
private:
	SDL_Renderer *renderer;

public:
	Renderer(Display *display, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	Renderer(Display *display);

	void SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
};

#endif