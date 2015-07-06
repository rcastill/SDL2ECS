#include "transform.h"

IntegerProperty::IntegerProperty(int *pinteger) : integer(pinteger)
{
}

IntegerProperty::operator int()
{
	return *integer;
}
	
IntegerProperty	&IntegerProperty::operator+=(double other)
{
    *integer = (int) (*integer + other);
	return *this;
}

IntegerProperty &IntegerProperty::operator-=(double other)
{
    *integer = (int) (*integer - other);
	return *this;
}

IntegerProperty &IntegerProperty::operator*=(double other)
{
	*integer = (int) (*integer * other);
	return *this;
}

IntegerProperty &IntegerProperty::operator/=(double other)
{
    *integer = (int) (*integer / other);
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

Transform::Transform() : x(&rect.x), y(&rect.y), w(&rect.w), h(&rect.h), r(&rotation), enabled(true)
{
}

void Transform::SetEnabled(bool enabled)
{
	this->enabled = enabled;
}

SDL_Rect *Transform::GetSDLRect()
{
    if (enabled)
        return &rect;

    return NULL;
}

Transform::operator SDL_Rect*()
{
	if (enabled)
		return &rect;

	return NULL;
}

ostream &operator << (ostream &stream, Transform &transform)
{
	int x = transform.rect.x;
	int y = transform.rect.y;
	int w = transform.rect.w;
	int h = transform.rect.h;
	int r = transform.r;

	return stream << "{x: " << x << ", y: " << y << ", w: " << w << ", h: " << h << ", r: " << r << "}";
}
