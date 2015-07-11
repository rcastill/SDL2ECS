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
    for (unsigned int i = 0; i < cameras.size(); i++)
        delete cameras[i];

	SDL_DestroyRenderer(renderer);
}

void Renderer::Init()
{
    SDL_Window *window = display->GetSDLWindow();

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == NULL) {
		PushError(std::string(SDL_GetError()));
	}

	SetDrawColor(drawR, drawG, drawB, drawA);

    activeCamera = CreateCamera("Main");

    activeCamera->w = display->GetWidth();
    activeCamera->h = display->GetHeight();

    cameras.push_back(activeCamera);
}


SDL_Texture *Renderer::CreateTexture(SDL_Surface *surface)
{
	return SDL_CreateTextureFromSurface(renderer, surface);
}

void Renderer::Clear()
{
    int clearResult = SDL_RenderClear(renderer);

    if (clearResult < 0)
        std::cout << std::string(SDL_GetError()) << endl;
}

void Renderer::RenderTextures()
{
	assert(game != NULL);
	std::vector<Entity *> &entities = game->GetEntities();

	for (unsigned int i = 0; i < entities.size(); i++) {
		Texture *texture = entities[i]->GetTexture();

		if (texture != NULL)
            SDL_RenderCopyEx(renderer, texture->GetSDLTexture(), texture->GetFrame(), entities[i]->GetTransform().GetSDLRect(), entities[i]->GetTransform().r, NULL, SDL_FLIP_NONE);
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

bool Renderer::CameraExists(std::string name)
{
    for (unsigned int i = 0; i < cameras.size(); i++) {
        if (cameras[i]->GetName() == name)
            return true;
    }

    return false;
}

Camera *Renderer::CreateCamera(std::string name)
{
    if (CameraExists(name))
        return NULL;

    Camera *camera = new Camera(name);
    cameras.push_back(camera);
    return camera;
}

Camera *Renderer::GetCamera(std::string name)
{
    for (unsigned int i = 0; i < cameras.size(); i++) {
        if (cameras[i]->GetName() == name)
            return cameras[i];
    }

    return NULL;
}

void Renderer::SetActiveCamera(Camera *camera)
{
    if (camera == NULL)
        return;

    activeCamera = camera;
}

void Renderer::SetActiveCamera(std::string name)
{
    SetActiveCamera(GetCamera(name));
}

void Renderer::DestroyCamera(std::string name)
{
    std::vector<Camera*>::iterator remove = cameras.begin();
    Camera *camera = NULL;

    for (unsigned int i = 0; i < cameras.size(); i++) {
        if (cameras[i]->GetName() == name) {
            camera = cameras[i];
            remove += i;
        }
    }

    if (camera == NULL)
        return;

    cameras.erase(remove);
    delete camera;
}
