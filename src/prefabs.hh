#include "entity.h"
#include "ccomponents.hh"

class Player : public Entity
{
public:
	Player()
    {
    }
	
	void Init()
    {
        // FIX IT
        AddComponent(new WASDController);
        //AddComponent<WASDController>();
    }
};
