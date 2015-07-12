#ifndef CAMERA_H
#define CAMERA_H

#include <string>
#include "transform.h"
#include "entity.h"
#include "component.h"

class Entity;
class Component;

class Camera
{
private:
    Transform *followed;
    
public:
    int x;
    int y;
    int w;
    int h;
    
    Camera();
    Camera(const Camera &other);

    void SetPosition(int x, int y);
    void SetDimension(int w, int h);

    void Follow(Transform &transform);
    void Follow(Entity *entity);
    void Follow(Component *component);

    void Unfollow();
};

#endif
