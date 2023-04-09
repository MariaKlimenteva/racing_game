#ifndef _CSURFACE_H_
#define _CSURFACE_H_
 
#include <SDL.h>
 
class Surface 
{
    public:
    Surface();
 
    public:
    static SDL_Surface* OnLoad(char* File, SDL_Window *window);
};
 
#endif