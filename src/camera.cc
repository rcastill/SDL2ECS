#include "camera.h"

Camera::Camera(std::string pname) : name(pname), followed(NULL)
{
}

std::string Camera::GetName()
{
    return name;
}

void Camera::SetPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Camera::SetDimension(int w, int h)
{
    this->w = w;
    this->h = h;
}


void Camera::Follow(Transform &transform)
{
    followed = &transform;
}

void Camera::Follow(Entity *entity)
{
    followed = &entity->GetTransform();
}

void Camera::Follow(Component *component)
{
    followed = &component->GetTransform();
}

void Camera::Unfollow()
{
    followed = NULL;
}

