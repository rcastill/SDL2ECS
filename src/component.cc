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

/*template <typename T>
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
}*/

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

