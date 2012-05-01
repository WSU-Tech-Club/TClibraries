#pragma once
#ifdef WIN32
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#else
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#endif
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

int TCdraw(SDL_Surface* image, SDL_Surface* screen, int x, int y);
int TCdrawSpr(SDL_Surface* image, SDL_Rect *clip, SDL_Surface* screen, int x, int y);
SDL_Rect *newRect(int x, int y, int w, int h);
SDL_Color makeColor(int r, int g, int b);
SDL_Surface *LoadImageCK(string filename);
string itos(int n);