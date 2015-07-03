#include "game.h"

Game::Game() : running(true), display(NULL), timeController(NULL), renderer(NULL) {}

Game::~Game()
{
	for (unsigned int i = 0; i < systems.size(); i++)
		delete systems[i];

	for (unsigned int i = 0; i < entities.size(); i++)
		delete entities[i];

	if (display != NULL)
		delete display;

	if (timeController != NULL)
		delete timeController;

	if (renderer != NULL)
		delete renderer;
}

Display *Game::GetDisplay()
{
	return display;
}

Time *Game::GetTimeController()
{
	return timeController;
}

Renderer *Game::GetRenderer()
{
	return renderer;
}

void Game::LoadDisplay(string title, int width, int height)
{
	display = new Display(title, width, height);
}

void Game::LoadTimeController(double frameRate)
{
	timeController = new Time(frameRate);
}

void Game::LoadRenderer()
{
	renderer = new Renderer(display);
}

void Game::LoadRenderer(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	renderer = new Renderer(display, r, g, b, a);
}

void Game::LoadSystem(System *psystem)
{
	systems.push_back(psystem);
}

void Game::AddEntity(Entity *entity)
{
	entities.push_back(entity);
}

template <typename T>
void Game::Instantiate()
{
	T *t = new T;
	AddEntity(t);
}

void Game::Start()
{
	assert(renderer != NULL);

	// Load Textures
	for (unsigned int i = 0; i < entities.size(); i++) {
		Texture *texture = entities[i]->GetTexture();

		if (texture != NULL)
			texture->Load(renderer, entities[i]);
	}

	// Initialize entities
	for (unsigned int i = 0; i < entities.size(); i++) {
		entities[i]->SetGame(this);
		entities[i]->Init();
	}

	while (running) {
		// Iterate through every entity registered in the game
		for (int i = 0; i < entities.size(); i++) {
			vector<Component*> &components = entities[i]->GetComponents();

			// Trigger OnUpdate on each component
			for (unsigned int i = 0; i < components.size(); i++)
				components[i]->OnUpdate();
		}
	}
}

vector<Entity*> &Game::GetEntities()
{
	return entities;
}