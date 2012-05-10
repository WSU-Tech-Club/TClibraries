#pragma once
#include "TCut.h"

typedef struct TCcursor
{
	int position;
	bool show;
	int delay;
	int tick;
}TCcursor;

class TCtextBox
{
private:
	string text;
	TCcursor cursor;
	
	SDL_Rect *TextSize;
	SDL_Rect *dispRect;
	SDL_Surface* img;
	TTF_Font *font;

	bool selected;


public:
	TCtextBox(int xPos, int yPos);

	void display(SDL_Surface* screen);
	void handleInput(SDL_Event e);

	void setText(string newText);
	void renderText();

	bool isSelected();

};