#ifndef TCWIDGET_H
#define TCWIDGET_H
#include "TCut.h"

class TCwidget
{
protected:
	SDL_Rect *rect;


public:
	TCwidget();

	void display()=0;

	void handleInput(SDL_Event event)=0;




};

TCwidget::TCwidget()
{
	
}

#endif