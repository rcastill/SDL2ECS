#include "renderer.h"

Renderer::Renderer(Display *display, Uint8 r, Uint8 g, Uint8 b, Uint8 a) : renderer(NULL)
{
	if (display == NULL) {
		PushError("Display must be loaded!");
		return;
	}

	renderer = SDL_CreateRenderer(display.GetSDLWindow(), -1, SDL_RENDERER_ACCELERATED);

	if (renderer == NULL) {
		PushError(string(SDL_GetError()));
	}

	SetDrawColor(r, g, b, a);
}

Renderer::Renderer(Display *display) : Renderer(display, DEFAULT_DRAW_COLOR_R, DEFAULT_DRAW_COLOR_G, DEFAULT_DRAW_COLOR_B, DEFAULT_DRAW_COLOR_A)
{
}

void Renderer::SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}