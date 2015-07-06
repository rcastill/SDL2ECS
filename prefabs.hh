#include "api/include/entity.h"
#include "ccomponents.hh"

class Player : public Entity
{
public:
	void Init()
    {
        SetTexture("res/mario.png");
        
        AddComponent<WASDController>();
        AddComponent<Zoomer>();
        AddComponent<Rotator>();
    }
};

class GlobalBehaviours : public Entity
{
    public:
        void Init()
        {
            AddComponent<GlobalInputManager>();
        }
};
