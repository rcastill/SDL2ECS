#include "time.h"

Time::Time(int fps) : timePerFrame((int) 1000.0f / fps)
{
}

void Time::Init()
{
    startTime = SDL_GetTicks();
}

Uint32 Time::GetElapsed()
{
    return SDL_GetTicks() - startTime;
}

float Time::GetFPS()
{
    assert(game != NULL);
    return game->GetFrameCount() / (GetElapsed() / 1000.0f);
}

float Time::GetDeltaTime()
{
    return deltaTime;
}


void Time::Update()
{
    deltaTime = frameTime / 1000.0f;
    frameTime = SDL_GetTicks();
}

void Time::CapFrameRate()
{
    frameTime = SDL_GetTicks() - frameTime;

    if (frameTime < timePerFrame)
        SDL_Delay(timePerFrame - frameTime);
}    

