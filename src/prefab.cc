#include "prefab.h"

template <typename T>
T *Prefab<T>::Instantiate(Game &game)
{
	T *prefab = new T;
	game.AddEntity(prefab);
	return prefab;
}