#include "component.h"

Component::Component() : game(NULL), entity(NULL)
{
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

template <typename T>
void Component::Instantiate()
{
	assert(game != NULL);
	game->Instantiate<T>();
}

template <typename Derived>
Derived *Component::GetComponent()
{
	assert(entity != NULL);
	return entity->GetComponent<Derived>();
}

void Component::SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	assert(game != NULL)
	Renderer *renderer = game->GetRenderer();

	assert(renderer != NULL);
	renderer->SetDrawColor(r, g, b, a);
}