#include "entity.h"

Entity::Entity() : game(NULL), texture(NULL)
{
}

Entity::~Entity()
{
	for (unsigned int i = 0; i < components.size(); i++)
		delete components[i];

	if (texture != NULL)
		delete texture;
}

void Entity::Init()
{
}

vector<Component*>& Entity::GetComponents()
{
	return components;
}

void Entity::AddComponent(Component *component)
{
    components.push_back(component);
}

/*template <typename Derived>
Derived *Entity::GetComponent()
{
	for (unsigned int i = 0; i < components.size(); i++) {
		Derived *cast = dynamic_cast<Derived *>(components[i]);

		if (cast != 0)
			return cast;
	}

	return NULL;
}

template <typename T>
T *Entity::AddComponent()
{
	T *component = new T;
	component->SetEntity(this);
	components.push_back(component);
	return component;
}*/

void Entity::SetGame(Game *game)
{
	if (this->game == NULL)
		this->game = game;
}

void Entity::SetTexture(string path)
{
	if (texture == NULL)
		texture = new Texture(path);
}

Texture *Entity::GetTexture()
{
	return texture;
}

void Entity::InitComponents()
{
	for (unsigned int i = 0; i < components.size(); i++) {
		components[i]->SetGame(game);
        components[i]->SetEntity(this);
		components[i]->Init();
	}
}

Transform &Entity::GetTransform()
{
	return transform;
}
