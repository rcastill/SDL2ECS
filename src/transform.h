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

    SDL_Rect *GetSDLRect();
	operator SDL_Rect*();

    friend ostream &operator << (ostream &stream, Transform &transform);
};

ostream &operator << (ostream &stream, Transform &transform);

#endif
