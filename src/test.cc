#include "test.h"

namespace SDL2
{

Renderer::Renderer(SDL_Renderer *renderer)
{
    this->renderer = renderer;
}

Renderer::Renderer(Renderer &&other)
{
    SDL_Renderer *backup = renderer;
    renderer = other.renderer;
    other.renderer = backup;
}

Renderer::Renderer() : renderer(NULL)
{
}

Renderer::~Renderer()
{
    if (renderer != NULL)
        SDL_DestroyRenderer(renderer);
}

Renderer &Renderer::operator=(Renderer &&other)
{
    SDL_Renderer *backup = this->renderer;
    this->renderer = other.renderer;
    other.renderer = backup;
    return *this;
}

Renderer::operator SDL_Renderer *()
{
    return renderer;
}

Window::Window(string title, int width, int height)
{
    this->title = title;
    this->width = width;
    this->height = height;

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
}

Window::~Window()
{
    if (window != NULL)
        SDL_DestroyWindow(window);
}

Window::operator SDL_Window *()
{
    return window;
}

Renderer Window::CreateRenderer()
{
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    return Renderer(renderer);
}

}
