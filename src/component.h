#ifndef COMPONENT_H
#define COMPONENT_H

#include <SDL2/SDL.h>
#include "game.h"
#include "entity.h"
#include "input.h"
#include <cassert>
#include <iostream>
#include "transform.h"

class Entity;

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

	Transform &GetTransform();

	template <typename T>
	void Instantiate();
	
	template <typename T>
	T *AddComponent();

	template <typename Derived>
	Derived *GetComponent();

	void SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);

	bool GetKeyDown(SDL_Keycode key);
	bool GetKeyPressed(SDL_Keycode key);

	string GetError();
	
	virtual bool Init();
	virtual void Update();
};

#endif