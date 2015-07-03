#ifndef WASDCONTROLLER_H
#define WASDCONTROLLER_H

#include "component.h"

class WASDController : public Component
{
public:
	WASDController();

	bool Init();
	void Update();
};

#endif