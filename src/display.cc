#include "display.h"

Display::Display() : window(NULL), surface(NULL)
{
}

Display::Display(string ptitle, int width, int height) : title(ptitle)
{
	this->width = width;
	this->height = height;
}

Display::Display(const Display& display) : title(display.title)
{
	this->width = display.width;
	this->height = display.height;
}

Display::~Display()
{
	if (window != NULL)
		SDL_DestroyWindow(window);

	IMG_Quit();
	SDL_Quit();
}

SDL_Window *Display::GetSDLWindow()
{
	return window;
}

string Display::GetTitle()
{
	return title;
}

int Display::GetWidth()
{
	return width;
}

int Display::GetHeight()
{
	return height;
}

void Display::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		PushError(string(SDL_GetError()));
		return;
	}

	window = SDL_CreateWindow(
		title.c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width,
		height,
		SDL_WINDOW_SHOWN);

	if (window == NULL) {
		PushError(string(SDL_GetError()));
		return;
	}

	surface = SDL_GetWindowSurface(window);

	// Image sub module
	IMG_Init(IMG_INIT_PNG);

	/*
	* TODO: Add more flags / maybe init in separate system
	*/
}

Display &Display::operator=(Display &&other)
{
	title = other.title;
	width = other.width;
	height = other.height;
	window = other.window;
	surface = other.surface;

	other.window = NULL;
	other.surface = NULL;
}