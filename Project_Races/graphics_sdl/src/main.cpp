#include "window.h"

int main() {
    SDL_SetMainReady(); // tell SDL that we handle main() function ourselves, comes with the SDL_MAIN_HANDLED macro
    sdl sdl;
    window window;
    SDL_Renderer *renderer = nullptr;
    window.loop(renderer);

    exit(EXIT_SUCCESS);
}