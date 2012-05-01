#ifndef FPS_REG_H
#define FPS_REG_H
#ifdef WIN32
#include "SDL.h"
#else
#include "SDL/SDL.h"
#endif

class FPS_Regulator
{
private:
	int ticks;
	int FPS;
public:
	FPS_Regulator(int nFPS);

	void start();
	void killTime();

};



#endif