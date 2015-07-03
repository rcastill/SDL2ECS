#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "entity.h"
#include "renderer.h"

class Entity;
class Renderer;

using namespace std;

class Texture
{
private:
	string path;
	SDL_Texture *texture;

	SDL_Rect *frame;

	int width, height;

public:
	/*
	* TODO: Add constructor allowing to select a section of the surface (frame)
	*/
	Texture(string path);
	~Texture();

	bool Load(Renderer *renderer, Entity *entity);

	SDL_Rect *GetFrame();

	int GetWidth();
	int GetHeight();

	operator SDL_Texture*();
};

#endif