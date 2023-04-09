#include "surface.h"
#include "game.h"

Surface::Surface() {}

SDL_Surface* Surface::OnLoad(char* File, SDL_Window *window) 
{
    SDL_Surface* Surf_Temp = NULL;
    SDL_Surface* Surf_Return = NULL;
 
    if((Surf_Temp = SDL_LoadBMP(File)) == NULL) 
    {
        return NULL;
    }

    Surf_Return = SDL_ConvertSurfaceFormat(Surf_Temp, SDL_GetWindowPixelFormat(window), 0); // !!!БЫТЬ ВНИМАТЕЛЬНОЙ возможна ошибка с SDL_Window *window!!!
    SDL_FreeSurface(Surf_Temp);
 
    return Surf_Return;
}
// Создаем поверхность, возвращаем ее, но не освобождаем старую