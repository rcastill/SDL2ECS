#include "game.h"

Game::Game() : running(true), display(NULL), time(NULL), renderer(NULL), input(NULL), frameCount(0)
{
}

Game::~Game()
{
	for (unsigned int i = 0; i < entities.size(); i++)
		delete entities[i];

	if (display != NULL)
		delete display;

	if (time != NULL)
		delete time;

	if (renderer != NULL)
		delete renderer;
}

Display *Game::GetDisplay()
{
	return display;
}

Renderer *Game::GetRenderer()
{
	return renderer;
}

Input *Game::GetInput()
{
	return input;
}

Uint32 Game::GetFrameCount()
{
    return frameCount;
}

Time *Game::GetTime()
{
    return time;
}

void Game::LoadDisplay(string title, int width, int height)
{
	display = new Display(title, width, height);
}

void Game::LoadTimeController(double frameRate)
{
	time = new Time(frameRate);
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

    assert(time != NULL);

    time->SetGame(this);
    time->Init();

	while (running) {
        // Notify new iteration
        time->Update();

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

        // Update frameCount
        frameCount++;

		// Reset events
		input->Reset();

        // Cap frame rate
        time->CapFrameRate();
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
