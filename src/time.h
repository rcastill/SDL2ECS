#ifndef TIME_H
#define TIME_H

#include "SDL2/SDL.h"
#include "system.h"
#include "game.h"
#include <cassert>

class Time : public System
{
private:
    Uint32 startTime;
    Uint32 frameTime;
    Uint32 timePerFrame;

    float deltaTime;

public:
    Time(int fps = 60);

    void Init();
    Uint32 GetElapsed();
    float GetFPS();
    float GetDeltaTime();

    // Caps frame rate as necessary
    void Update();
    void CapFrameRate();
};

#endif
