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

    bool statictex;

public:
	/*
	* TODO: Add constructor allowing to select a section of the surface (frame)
	*/
	Texture(string path, bool statictex = false);
	~Texture();

	bool Load(Renderer *renderer, Entity *entity);

	SDL_Rect *GetFrame();
    SDL_Texture *GetSDLTexture();

	int GetWidth();
	int GetHeight();

    void SetStatic(bool on);
    bool IsStatic();

	operator SDL_Texture*();
};

#endif
