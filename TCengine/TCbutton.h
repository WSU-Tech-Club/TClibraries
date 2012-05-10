#ifndef BUTTON_H
#define BUTTON_H
#include <string>
#include "TCut.h"

using std::string;

class Button : public TCwidget
{
private:
	SDL_Surface* image[2];
	int isPressed;
	bool lock;

public:
	Button(string baseImageName, int x, int y, int width, int height);

	void display(SDL_Surface* screen);
	void handleInput(SDL_Event event);

	bool wasClicked(int clickX, int clickY);
	bool isClicked();
	void setClick(bool nPress);
	bool wasClickedState( int clickX, int clickY);

	void Lock();
};
#endif