#include "TCut.h"

//TCdraw
//Jeromy Johnson
//A safe, simple, SDL powered drawing function
//Puts the specified image on the screen at the coordinates specified
int TCdraw( SDL_Surface* image, SDL_Surface* screen, int x, int y )
{
	if(image == NULL){
		printf("ERROR: image file null.\n");
		return 0;}
	SDL_Rect destination = {x,y,0,0};
	SDL_BlitSurface(image, NULL, screen, &destination);
	return 1;		
}

//TCdrawSpr
//Jeromy Johnson
//Used for blitting images from sprite sheets
//clip specifies the portion of the image to blit to the screen
int TCdrawSpr( SDL_Surface* image, SDL_Rect *clip, SDL_Surface* screen, int x, int y )
{
	if(image == NULL){
		printf("ERROR: image file null.\n");
		return 0;}
	if(clip == NULL){
		printf("ERROR: clip rect is null.\n");
		return 0;}
	SDL_Rect destination = {x,y,0,0};
	SDL_BlitSurface(image, clip, screen, &destination);
	return 1;	
}

SDL_Rect * newRect( int x, int y, int w, int h )
{
	SDL_Rect *temp = new SDL_Rect;
	temp->x = x;
	temp->y = y;
	temp->h = h;
	temp->w = w;
	return temp;
}

//makeColor
//Jeromy Johnson
//Returns an SDL_color object with the specified rgb codes
SDL_Color makeColor( int r, int g, int b )
{
	SDL_Color n = {r,g,b};
	return n;
}

//LoadImageCK
//Jeromy Johnson
//loads specified image and turns all pixels of color RGB(255,0,255) transparent
SDL_Surface *LoadImageCK(string filename)
{
	SDL_Surface *newImage = IMG_Load(filename.c_str());
	SDL_Surface *keyedImage = NULL;

	if(newImage != NULL)
	{
		keyedImage = SDL_DisplayFormat(newImage);

		SDL_FreeSurface(newImage);

		if(keyedImage != NULL)
		{
			Uint32 colorkey = SDL_MapRGB(keyedImage->format, 0xFF, 0, 0xFF);

			SDL_SetColorKey(keyedImage, SDL_SRCCOLORKEY, colorkey);

			return keyedImage;
		}
		else
		{
			return NULL;
		}

	}
	else
	{
		return NULL;
	}
}

string itos( int n )
{
	stringstream s;
	s << n;
	return s.str();
}
