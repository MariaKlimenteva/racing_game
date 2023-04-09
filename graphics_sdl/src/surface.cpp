#include "surface.h"
#include "game.h"
//--------------------------------------------------------------------------
Surface::Surface() 
{

}
//--------------------------------------------------------------------------
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
//--------------------------------------------------------------------------
bool Surface::Draw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y) // есть две поверхности : одна - на которой рисуем, вторая - которую рисуем
{                                                                               // помещаем Surf_Src поверх Surf_Dest. X, Y - позиция на Surf_Dest, к которой мы рисуем эту поверхность
    if(Surf_Dest == NULL || Surf_Src == NULL) 
    {
        return false;
    }
 
    SDL_Rect DestR;
 
    DestR.x = X;
    DestR.y = Y;
 
    SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);
 
    return true;
}