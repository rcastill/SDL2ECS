#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

class IntegerProperty
{
private:
	int *integer;

public:
	IntegerProperty(int *integer);

	operator int();	

	IntegerProperty	&operator+=(int other);
	IntegerProperty &operator-=(int other);
	IntegerProperty &operator*=(int other);
	IntegerProperty &operator/=(int other);
	IntegerProperty &operator%=(int other);
	IntegerProperty &operator=(int other);
};

class Transform
{
private:
	SDL_Rect rect;
	int rotation;

	bool enabled;

public:
	IntegerProperty x;
	IntegerProperty y;
	IntegerProperty w;
	IntegerProperty h;
	IntegerProperty r;

	Transform();

	void SetEnabled(bool enabled);

	operator SDL_Rect*();
};

ostream &operator << (ostream &stream, const Transform &transform);

#endif