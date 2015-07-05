#include "component.h"
#include <iostream>

class WASDController : public Component
{
public:
	WASDController()
        {
        }
        
	bool Init()
        {
            return true;
        }
        
	void Update()
        {
            if (GetKeyDown(SDLK_ESCAPE))
                Stop();

            if (GetKeyDown(SDLK_t)) {
                WASDController *wasdcontroller = GetComponent<WASDController>();
                cout << wasdcontroller << " == " << this << endl;
            }

            if (GetKeyDown(SDLK_f)) {
                float fps = GetTimeSystem().GetFPS();
                cout << "FPS: " << fps << endl;
            }

            Transform &transform = GetTransform();

            if (GetKeyPressed(SDLK_d))
                    transform.x += 10;

            if (GetKeyPressed(SDLK_w))
                    transform.y -= 10;

            if (GetKeyPressed(SDLK_a))
                    transform.x -= 10;

            if (GetKeyPressed(SDLK_s))
                    transform.y += 10;

            if (GetKeyDown(SDLK_v))
                cout << transform << endl;
        }
};

