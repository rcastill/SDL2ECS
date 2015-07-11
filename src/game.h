#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <iostream>
#include "entity.h"
#include "display.h"
#include "time.h"
#include "texture.h"
#include "input.h"
#include "renderer.h"

#include <vector>
#include <cassert>

class Entity;
class Time;

using namespace std;

class Game
{
private:
	bool running;
	
	vector<Entity*> entities;

	Display *display;
	Time *time;
	Renderer *renderer;
	Input *input;

    Uint32 frameCount;

public:
	Game();
	~Game();

	void LoadDisplay(string title, int width, int height);
	void LoadTimeController(double frameRate);
	
	void LoadRenderer();
	void LoadRenderer(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);

	void LoadInput();

	void AddEntity(Entity *entity);

	template <typename T>
	T *Instantiate();

	vector<Entity*> &GetEntities();

	Display *GetDisplay();
	Time *GetTime();
	Renderer *GetRenderer();
	Input *GetInput();

    Uint32 GetFrameCount();

    void Init();

	void Start();
    void Stop();
};

template <typename T>
T *Game::Instantiate()
{
	T *entity = new T;
	AddEntity(entity);
    return entity;
}

#endif
