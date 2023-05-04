#ifndef _CSURFACE_H_
#define _CSURFACE_H_
 
#include <SDL.h>
#include <SDL2/SDL.h>

class Surface 
{
    public:
    Surface();
 
    public:
    static SDL_Surface* OnLoad(char* File, SDL_Window *window);
    static bool Draw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y);
};
 
#endif