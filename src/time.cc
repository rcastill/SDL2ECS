#include "time.h"

Time::Time()
{
}

Time::Time(double frameRate)
{
	frameTime = 1.0 / frameRate;
}

double Time::GetFrameTime() const
{
	return frameTime;
}