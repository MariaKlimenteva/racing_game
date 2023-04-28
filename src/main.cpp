#include <iostream>

#include "game.h"
//--------------------------------------------------------------------------
int main() 
{
    Game Races;
    
    SDL_SetMainReady();

    Races.Init();
    SDL_Event* Event;
    while(true) 
    {
        Races.OnEvent(Event);
        Races.Loop();
        Races.Render();
    }
    Races.Cleanup();

    return Races.Execute();
}
//--------------------------------------------------------------------------