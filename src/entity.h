#ifndef ENTITY_H
#define ENTITY_H

#include "component.h"
#include "game.h"
#include <vector>

using namespace std;

class Entity
{
private:
	Game *game;
	vector<Component *> components;

protected:
	// Transform

public:
	Entity();
	void SetGame(Game *game);

	void AddComponent(Component *component);
	vector<Component*>& GetComponents();

	template <typename Derived>
	Derived *GetComponent();

	void InitComponents();
};

#endif