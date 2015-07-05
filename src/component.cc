#include "component.h"

Component::Component() : game(NULL), entity(NULL)
{
}

Component::~Component()
{
}

bool Component::Init()
{
    return true;
}

void Component::Update()
{
}

Transform &Component::GetTransform()
{
	assert(entity != NULL);
	return entity->GetTransform();
}

void Component::PushError(string failureDetail)
{
	this->failureDetail = failureDetail;
}

string Component::GetError()
{
	return failureDetail;
}

void Component::SetGame(Game *game)
{
	if (this->game == NULL)
		this->game = game;
}

void Component::SetEntity(Entity *entity)
{
	if (this->entity == NULL)
		this->entity = entity;
}

Time &Component::GetTimeSystem()
{
    assert(game != NULL);
    return *game->GetTime();
}

void Component::SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	assert(game != NULL);
	Renderer *renderer = game->GetRenderer();

	assert(renderer != NULL);
	renderer->SetDrawColor(r, g, b, a);
}

bool Component::GetKeyDown(SDL_Keycode key)
{
	assert(game != NULL);
	Input *input = game->GetInput();

	assert(input != NULL);
	return input->GetKeyDown(key);
}

bool Component::GetKeyPressed(SDL_Keycode key)
{
	assert(game != NULL);
	Input *input = game->GetInput();

	assert(input != NULL);
	return input->GetKeyPressed(key);
}

void Component::Stop()
{
    assert(game != NULL);
    game->Stop();
}

