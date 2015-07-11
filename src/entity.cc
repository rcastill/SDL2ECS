#include "entity.h"

Entity::Entity() : texture(NULL)
{
}

Entity::~Entity()
{
	for (unsigned int i = 0; i < components.size(); i++)
		delete components[i];

	if (texture != NULL)
		delete texture;
}

vector<Component*>& Entity::GetComponents()
{
	return components;
}

void Entity::AddComponent(Component *component)
{
    components.push_back(component);
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

void Entity::Init(Game *game)
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
