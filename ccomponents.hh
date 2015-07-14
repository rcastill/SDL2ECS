#include "api/include/component.h"
#include <iostream>

class WASDController : public Component
{
public:
    int speed;
    Camera *mainCamera;

	WASDController()
        {
            // Default values            
            speed = 10;


        }
        
	bool Init()
        {
            mainCamera = GetCamera("Main");
            return true;
        }
        
	void Update()
        {
            if (GetKeyDown(SDLK_p)) {
                cout << GetDeltaTime() << endl;
            }

            Transform &transform = GetTransform();

            if (GetKeyPressed(SDLK_d))
                transform.x += speed;

            if (GetKeyPressed(SDLK_w))
                transform.y -= speed;

            if (GetKeyPressed(SDLK_a))
                transform.x -= speed;

            if (GetKeyPressed(SDLK_s))
                transform.y += speed;

            if (GetKeyDown(SDLK_v))
                cout << transform << endl;
        }
};

class Zoomer : public Component
{
    public:
        void Update()
        {
            Transform &transform = GetTransform();

            if (GetKeyPressed(SDLK_x)) {
                transform.w *= 1.05;
                transform.h *= 1.05;
            }

            if (GetKeyPressed(SDLK_z)) {
                transform.w *= 0.95;
                transform.h *= 0.95;
            }
        }
};

class Rotator : public Component
{
    public:
        void Update()
        {
            Transform &transform = GetTransform();

            if (GetKeyPressed(SDLK_e))
                transform.r += 1;

            if (GetKeyPressed(SDLK_q))
                transform.r -= 2;
        }
};

class GlobalInputManager : public Component
{
    public:
        Camera *mainCamera;

        bool Init()
        {
            mainCamera = GetCamera("Main");
            assert(mainCamera != NULL);
            return true;
        }

        void Update()
        {
            if (GetKeyDown(SDLK_ESCAPE))
                Stop();

            if (GetKeyDown(SDLK_f)) {
                float fps = GetTimeSystem().GetFPS();
                cout << "FPS: " << fps << endl;
            }

            if (GetKeyPressed(SDLK_l))
                mainCamera->x += 5;
            
            if (GetKeyPressed(SDLK_j))
                mainCamera->x -= 5;

            if (GetKeyPressed(SDLK_k))
                mainCamera->y += 5;

            if (GetKeyPressed(SDLK_i))
                mainCamera->y -= 5;
        }
};



