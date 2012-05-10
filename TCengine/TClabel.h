#ifndef TCLABEL_H
#define TCLABEL_H
#include "TCut.h"

class TClabel : public TCwidget
{
public:
	TClabel();
	TClabel(string text);

	void display(SDL_Surface* screen);
	void handleInput(SDL_Event event);

	void setText(string nText);
private:
	string labelText;
	SDL_Surface *image;


};

void TClabel::display( SDL_Surface* screen )
{
	if(image != NULL)
	{
		if(rect != NULL)
		{
			SDL_BlitSurface(image,NULL,screen,rect);
		}
		else
		{
			printf("invalid SDL_Rect.\n");
		}
	}
	else
	{
		printf("No image Loaded.\n");
	}
}

#endif