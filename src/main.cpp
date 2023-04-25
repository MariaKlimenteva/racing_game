#include <iostream>

#include "game.h"
//--------------------------------------------------------------------------
int main() 
{
    Game Races;
    
    SDL_SetMainReady();

    Races.Init();
    while(true) 
    {
        SDL_Event* Event;
        Races.OnEvent(Event);
        Races.Loop();
        Races.Render();
    }
    Races.Cleanup();

    return Races.Execute();
}
//--------------------------------------------------------------------------