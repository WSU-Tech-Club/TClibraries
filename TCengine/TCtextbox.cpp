#include "TCtextbox.h"

TCtextBox::TCtextBox( int xPos, int yPos, int width, int height)
{
	dispRect = newRect(xPos, yPos, width, height);
	TextSize = newRect(3,3,width - 6, height - 6);
	font = TTF_OpenFont("monofont.ttf",10);

}

