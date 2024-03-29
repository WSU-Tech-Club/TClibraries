#include "TCbutton.h"


Button::Button( string baseImageName, int x, int y, int width, int height) : TCwidget()
{
	string temp;
	rect = newRect(x,y,width,height);
	temp = baseImageName + "Up.png";
	image[0] = LoadImageCK(temp);
	temp = baseImageName + "Down.png";
	image[1] = LoadImageCK(temp);
	isPressed = 0;
	lock = false;
}

void Button::display( SDL_Surface* screen )
{
	if(image[isPressed] != NULL)
	{
		SDL_BlitSurface(image[isPressed], NULL, screen, rect);
	}
	else
	{
		printf("No image loaded for button.\n");
	}
}

bool Button::wasClicked( int clickX, int clickY)
{
	if(lock)
		return false;
	if(clickX >= rect->x && clickX <= rect->x + rect->w && clickY >= rect->y && clickY <= rect->y + rect->h)
	{
		isPressed = (isPressed + 1) % 2;
		return isPressed == 1;
	}
	else
		return false;
}

bool Button::wasClickedState( int clickX, int clickY)
{
	if(clickX >= rect->x && clickX <= rect->x + rect->w && clickY >= rect->y && clickY <= rect->y + rect->h)
	{
		return true;
	}
	else
		return false;
}

bool Button::isClicked()
{
	return (!lock) && (isPressed == 1);
}

void Button::setClick( bool nPress )
{
	if(nPress)
		isPressed = 1;
	else
		isPressed = 0;
}

void Button::Lock()
{
	lock = true;
}

void Button::handleInput( SDL_Event event )
{
	if(event->type == SDL_MOUSEBUTTONUP)
	{
		wasClicked(event->button.x,event->button.y)';
	}
}


