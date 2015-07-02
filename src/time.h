#ifndef TIME_H
#define TIME_H

#include "SDL2/SDL.h"
#include "system.h"

class Time : public System
{
private:
	double frameTime;

public:
	Time();
	Time(double frameRate);

	double GetFrameTime() const;
};

#endif