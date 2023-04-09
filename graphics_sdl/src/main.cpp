#include <iostream>

#include "window.h"
#include "game.h"

int main() 
{
    Game Races;
    
    SDL_SetMainReady(); // tell SDL that we handle main() function ourselves, comes with the SDL_MAIN_HANDLED macro
    // sdl sdl;
    // window window;
    // SDL_Renderer *renderer = nullptr;
    // window.loop(renderer);

                // Initialize();
            
                // while(true) {
                //     Events();
                //     Loop();
                //     Render();
                // }
                // Cleanup();

    return Races.Execute();
}