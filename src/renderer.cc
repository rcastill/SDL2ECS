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

~Renderer()
{
	SDL_DestroyRenderer(renderer);
}

SDL_Texture *Renderer::CreateTexture(SDL_Surface *surface)
{
	return SDL_CreateTextureFromSurface(surface);
}

void Renderer::RenderTextures()
{
	assert(game != NULL);
	vector<Entity *> &entities = game->GetEntities();

	for (unsigned int i = 0; i < entities.size(); i++) {
		Texture *texture = entities[i]->GetTexture();

		if (texture != NULL)
			SDL_RenderCopy(renderer, texture, texture->GetFrame(), texture->GetTransform());
	}
}

void Renderer::SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}