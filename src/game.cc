#include "game.h"

Game::Game() : running(true), display(NULL), timeController(NULL), renderer(NULL), input(NULL)
{
}

Game::~Game()
{
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

Input *Game::GetInput()
{
	return input;
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

void Game::LoadInput()
{
	input = new Input();
}

void Game::AddEntity(Entity *entity)
{
	entities.push_back(entity);
}

template <typename T>
void Game::Instantiate()
{
	T *entity = new T;
	AddEntity(entity);
}

void Game::Start()
{

	// Initiate display
	display->Init();

    if (display->Check()) {
        cout << "Display error: " << display->GetError() << endl;
        return;
    }

	// Initiate input system
	input->Init();

    // Initiate renderer
    renderer->Init();

    if (renderer->Check()) {
        cout << "Renderer error: " << renderer->GetError() << endl;
        return;
    }

    renderer->SetGame(this);

	// Initialize entities
	for (unsigned int i = 0; i < entities.size(); i++) {
		entities[i]->SetGame(this);
		entities[i]->Init();
	}

	assert(renderer != NULL);

	// Load Textures
	for (unsigned int i = 0; i < entities.size(); i++) {
		Texture *texture = entities[i]->GetTexture();

		if (texture != NULL)
			texture->Load(renderer, entities[i]);
	}

	// Initialize components
	for (unsigned int i = 0; i < entities.size(); i++)
		entities[i]->InitComponents();

	while (running) {
		// Update events
		input->PollEvents();

		// Iterate through every entity registered in the game
		for (int i = 0; i < entities.size(); i++) {
			vector<Component*> &components = entities[i]->GetComponents();

			// Trigger OnUpdate on each component
			for (unsigned int i = 0; i < components.size(); i++)
				components[i]->Update();
		}

        // Clear screen
        renderer->Clear();

        // Render textures
        renderer->RenderTextures();

        // Update screen
        renderer->Update();

		// Reset events
		input->Reset();
	}
}

void Game::Stop()
{
    running = false;
}

vector<Entity*> &Game::GetEntities()
{
	return entities;
}
