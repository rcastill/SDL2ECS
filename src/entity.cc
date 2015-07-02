#include "entity.h"

Entity::Entity() : game(NULL) {}

vector<Component*>& Entity::GetComponents()
{
	return components;
}

template <typename Derived>
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
}

void Entity::SetGame(Game *game)
{
	if (this->game == NULL) {
		this->game = game;

		vector<Component>::iterator compit;

		for (compit = components.begin(); compit != components.end(); compit++)
			compit->SetGame(game);
	}
}

void Entity::InitComponents()
{
	vector<Component>::iterator compit;
	for (compit = components.begin(); compit != components.end(); compit++)
		compit->Init();
}