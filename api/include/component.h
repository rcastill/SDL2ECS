#ifndef COMPONENT_H
#define COMPONENT_H

#include <SDL2/SDL.h>
#include "game.h"
#include "entity.h"
#include "input.h"
#include "time.h"
#include <cassert>
#include <iostream>
#include "transform.h"
#include "renderer.h"
#include "camera.h"

class Entity;
class Time;
class Camera;

class Component
{
private:
	Game *game;
	Entity *entity;

	std::string failureDetail;

protected:
	void PushError(std::string failureDetail);

public:
	Component();
	virtual ~Component();

	void SetGame(Game *game);
	void SetEntity(Entity *entity);

    Entity *GetEntity();

	Transform &GetTransform();

	template <typename T>
	void Instantiate();
	
	template <typename T>
	T *AddComponent();

	template <typename Derived>
	Derived *GetComponent();

    Time &GetTimeSystem();

	void SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);

	bool GetKeyDown(SDL_Keycode key);
	bool GetKeyPressed(SDL_Keycode key);

    void GetMousePos(int &x, int &y);

    float GetDeltaTime();

	std::string GetError();

    void Stop();

    Camera *CreateCamera(std::string name);
    Camera *GetCamera(std::string name);
    
    void SetActiveCamera(Camera *camera);
    void SetActiveCamera(std::string name);

    void DestroyCamera(std::string name); 

	virtual bool Init();
	virtual void Update();
};

#ifndef LIBCOMPILE

template <typename T>
void Component::Instantiate()
{
	assert(game != NULL);
	game->Instantiate<T>();
}

template <typename T>
T *Component::AddComponent()
{
	assert(entity != NULL);
	return entity->AddComponent<T>();
}

template <typename Derived>
Derived *Component::GetComponent()
{
	assert(entity != NULL);
	return entity->GetComponent<Derived>();
}

#endif // LIBCOMPILE

#endif // COMPONENT_H
