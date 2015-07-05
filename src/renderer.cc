#include "renderer.h"

Renderer::Renderer(Display *display, Uint8 r, Uint8 g, Uint8 b, Uint8 a) : renderer(NULL)
{
	if (display == NULL) {
		PushError("Display must be loaded!");
		return;
	}

    this->display = display;
    drawR = r;
    drawG = g;
    drawB = b;
    drawA = a;
}

Renderer::Renderer(Display *display) : Renderer(display, DEFAULT_DRAW_COLOR_R, DEFAULT_DRAW_COLOR_G, DEFAULT_DRAW_COLOR_B, DEFAULT_DRAW_COLOR_A)
{
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(renderer);
}

void Renderer::Init()
{
    SDL_Window *window = display->GetSDLWindow();
    std::cout << "window = " << window << std::endl;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == NULL) {
		PushError(string(SDL_GetError()));
	}

	SetDrawColor(drawR, drawG, drawB, drawA);
}


SDL_Texture *Renderer::CreateTexture(SDL_Surface *surface)
{
	return SDL_CreateTextureFromSurface(renderer, surface);
}

void Renderer::Clear()
{
    int clearResult = SDL_RenderClear(renderer);

    if (clearResult < 0)
        std::cout << std::string(SDL_GetError()) << std::endl;
}

void Renderer::RenderTextures()
{
	assert(game != NULL);
	vector<Entity *> &entities = game->GetEntities();

	for (unsigned int i = 0; i < entities.size(); i++) {
		Texture *texture = entities[i]->GetTexture();

		if (texture != NULL)
			SDL_RenderCopy(renderer, (SDL_Texture*)texture, texture->GetFrame(), entities[i]->GetTransform());
	}
}

void Renderer::Update()
{
    SDL_RenderPresent(renderer);
}

void Renderer::SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    drawR = r;
    drawG = g;
    drawB = b;
    drawA = a;
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}
