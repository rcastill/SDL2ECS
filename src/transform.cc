#include "transform.h"



IntegerProperty::IntegerProperty(int *pinteger) : integer(pinteger)
{
}

IntegerProperty::operator int()
{
	return *integer;
}
	
IntegerProperty	&IntegerProperty::operator+=(int other)
{
	*integer += other;
	return *this;
}

IntegerProperty &IntegerProperty::operator-=(int other)
{
	*integer -= other;
	return *this;
}

IntegerProperty &IntegerProperty::operator*=(int other)
{
	*integer *= other;
	return *this;
}

IntegerProperty &IntegerProperty::operator/=(int other)
{
	*integer /= other;
	return *this;
}

IntegerProperty &IntegerProperty::operator%=(int other)
{
	*integer %= other;
	return *this;
}

IntegerProperty &IntegerProperty::operator=(int other)
{
	*integer = other;
	return *this;
}

Transform::Transform() : x(&rect.x), y(&rect.y), w(&rect.w), h(&rect.h), r(&rotation)
{
}

void Transform::SetEnabled(bool enabled)
{
	this->enabled = enabled;
}

Transform::operator SDL_Rect*()
{
	if (enabled)
		return &rect;

	return NULL;
}

ostream &operator << (ostream &stream, Transform &transform)
{
	int x = transform.x;
	int y = transform.y;
	int w = transform.w;
	int h = transform.h;
	int r = transform.r;

	return stream << "{x: " << x << ", y: " << y << ", w: " << w << ", h: " << h << ", r: " << r << "}";
}
