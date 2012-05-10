#ifndef TCWINDOW_H
#define TCWINDOW_H
#include "TCwidget.h"
#include <vector>

using std::vector;

class TCwindow
{
protected:
	vector<TCwidget*> menuObjects;

	SDL_Surface *screen;

	bool running;

	SDL_Event event;

public:
	TCwindow();

	int init();
	int run();

	void display();
	void handleInput();

};
#endif