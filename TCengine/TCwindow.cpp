#include "TCwindow.h"


TCwindow::TCwindow()
{

}

int TCwindow::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	TTF_Init();

	SDL_WM_SetCaption( "TC Application", NULL );

	screen = SDL_SetVideoMode(800,800,32,SDL_DOUBLEBUF | SDL_HWSURFACE);
}

int TCwindow::run()
{
	running = true;
	while (running)
	{
		handleInput();
		display();
	}
}

void TCwindow::display()
{
	for(int i = 0; i < menuObjects.size(); i++)
	{
		(menuObjects[i])->display();
	}
}

void TCwindow::handleInput()
{
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{
			running = false;
		}
		
		for(int i = 0; i < menuObjects.size(); i++)
		{
			menuObjects[i]->handleInput(&event);
		}
	}
}
