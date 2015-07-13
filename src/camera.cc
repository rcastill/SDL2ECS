#include "camera.h"

Camera::Camera() : followed(NULL), x(0), y(0), w(0), h(0)
{
}

Camera::Camera(const Camera &other)
{
    followed = other.followed;
    x = other.x;
    y = other.y;
    w = other.w;
    h = other.h;
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

SDL_Rect *Camera::GetRelativeRect(Entity *entity)
{
    Transform &transform = entity->GetTransform();
    relativeRect.x = transform.x - x;
    relativeRect.y = transform.y - y;
    relativeRect.w = transform.w;
    relativeRect.h = transform.h;
    return &relativeRect;
}
