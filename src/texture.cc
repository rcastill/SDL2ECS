#include "texture.h"

Texture::Texture(string ppath, bool stex) : path(ppath), texture(NULL), frame(NULL), statictex(stex)
{
}

Texture::~Texture()
{
	if (texture != NULL)
		SDL_DestroyTexture(texture);
}

bool Texture::Load(Renderer *renderer, Entity *entity)
{
	SDL_Surface *surface = IMG_Load(path.c_str());

	if (surface == NULL)
		return false;

	texture = renderer->CreateTexture(surface);
	SDL_QueryTexture(texture, NULL, NULL, &width, &height);

	Transform &transform = entity->GetTransform();
	transform.w = width;
	transform.h = height;

	SDL_FreeSurface(surface);
	return true;
}

SDL_Rect *Texture::GetFrame()
{
	return frame;
}

SDL_Texture *Texture::GetSDLTexture()
{
    return texture;
}

int Texture::GetWidth()
{
	return width;
}

int Texture::GetHeight()
{
	return height;
}

void Texture::SetStatic(bool on)
{
    statictex = on;
}

bool Texture::IsStatic()
{
    return statictex;
}

Texture::operator SDL_Texture *()
{
	return texture;
}
