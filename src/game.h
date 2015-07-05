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

using namespace std;

class Game
{
private:
	bool running;
	
	vector<Entity*> entities;

	Display *display;
	Time *timeController;
	Renderer *renderer;
	Input *input;

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
	void Instantiate();

	vector<Entity*> &GetEntities();

	Display *GetDisplay();
	Time *GetTimeController();
	Renderer *GetRenderer();
	Input *GetInput();

	void Start();
    void Stop();
};

#endif
