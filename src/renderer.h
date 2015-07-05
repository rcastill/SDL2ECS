#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include "system.h"
#include "display.h"
#include "entity.h"
#include "texture.h"
#include <iostream>

#define DEFAULT_DRAW_COLOR_R 255
#define DEFAULT_DRAW_COLOR_G 0
#define DEFAULT_DRAW_COLOR_B 0
#define DEFAULT_DRAW_COLOR_A 255

class Renderer : public System
{
private:
	SDL_Renderer *renderer;

    Display *display;
    Uint8 drawR;
    Uint8 drawG;
    Uint8 drawB;
    Uint8 drawA;

public:
	Renderer(Display *display, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	Renderer(Display *display);

    void Init();

	~Renderer();

	SDL_Texture *CreateTexture(SDL_Surface *surface);

    void Clear();
	void RenderTextures();
    void Update();

	void SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
};

#endif
