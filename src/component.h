#ifndef COMPONENT_H
#define COMPONENT_H

#include <SDL2/SDL.h>
#include "game.h"
#include "entity.h"
#include <cassert>
#include <iostream>

using namespace std;

class Component
{
private:
	Game *game;
	Entity *entity;

	string failureDetail;

protected:
	void PushError(string failureDetail);

public:
	Component();
	~Component();

	void SetGame(Game *game);
	void SetEntity(Entity *entity);

	template <typename T>
	void Instantiate();
	
	template <typename T>
	T *AddComponent();

	template <typename Derived>
	Derived *GetComponent();

	void SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);

	string GetError();
	
	virtual bool Init();
};

#endif