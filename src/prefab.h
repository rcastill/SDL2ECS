#ifndef PREFAB_H
#define PREFAB_H

#include "entity.h"
#include <vector>

using namespace std;

template <typename T>
class Prefab : public Entity
{
public:
	static T *Instantiate(Game &game);
};

#endif