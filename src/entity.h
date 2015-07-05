#ifndef ENTITY_H
#define ENTITY_H

#include "component.h"
#include "game.h"
#include "texture.h"
#include "transform.h"
#include <vector>

class Component;
class Texture;

using namespace std;

class Entity
{
private:
	Game *game;
	Texture *texture;
	vector<Component *> components;

	Transform transform;

public:
	Entity();
	virtual ~Entity();

	void SetGame(Game *game);
	
	void SetTexture(string path);
	Texture *GetTexture();

	Transform &GetTransform();

    // FIX IT
    void AddComponent(Component *compoenent);

	template <typename T>
	T *AddComponent();

	vector<Component*>& GetComponents();

	template <typename Derived>
	Derived *GetComponent();

	virtual void Init();
	
	void InitComponents();
};

#ifndef LIBCOMPILE

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

#endif // LIBCOMPILE

#endif // ENTITY_H
