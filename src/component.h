#ifndef COMPONENT_H
#define COMPONENT_H

#include <SDL2/SDL.h>
#include "game.h"
#include "entity.h"
#include <cassert>

class Component
{
private:
	Game *game;
	Entity *entity;

public:
	Component();
	~Component();

	void SetGame(Game *game);
	void SetEntity(Entity *entity);

	template <typename T>
	void Instantiate();
	
	template <typename Derived>
	Derived *GetComponent();

	void SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
	
	virtual void Init();
};

#endif