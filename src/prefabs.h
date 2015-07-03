#ifndef PREFABS_H
#define PREFABS_H

#include "entity.h"

#include "wasdcontroller.h"

class Player : public Entity
{
public:
	Player();
	void Init();
};

#endif