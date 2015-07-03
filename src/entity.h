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

	template <typename T>
	T *AddComponent();

	vector<Component*>& GetComponents();

	template <typename Derived>
	Derived *GetComponent();

	virtual void Init();
	
	void InitComponents();
};

#endif