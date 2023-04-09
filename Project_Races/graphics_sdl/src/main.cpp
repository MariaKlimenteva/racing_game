#include "window.h"
#include <iostream>
// #include <SDL_image.h>


int main() 
{
    SDL_SetMainReady(); // tell SDL that we handle main() function ourselves, comes with the SDL_MAIN_HANDLED macro
    sdl sdl;
    window window;
    SDL_Renderer *renderer = nullptr;
    window.loop(renderer);

    // IMG_LoadTexture
    exit(EXIT_SUCCESS);
}