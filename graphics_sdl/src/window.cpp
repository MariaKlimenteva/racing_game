#include "window.h"

void window::loop(SDL_Renderer *renderer) 
{
    while (true) 
    {
        SDL_Event event; // handle window closing
        if (SDL_PollEvent(&event) && (SDL_QUIT == event.type || (SDL_KEYDOWN == event.type && SDLK_ESCAPE == event.key.keysym.sym)))
            break;
        SDL_RenderClear(renderer); // re-draw the window
        SDL_RenderPresent(renderer);
    }
}

sdl::sdl()
{
    if(SDL_Init(SDL_INIT_VIDEO)) 
    {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
}

sdl::~sdl()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

window::window()
{
    SDL_Window   *window   = nullptr;
    SDL_Renderer *renderer = nullptr;

    if (SDL_CreateWindowAndRenderer(1024, 768, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS, &window, &renderer)) 
    {
        std::cerr << "Failed to create window and renderer: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    SDL_SetWindowTitle(window, "Races");
    SDL_SetRenderDrawColor(renderer, 210, 255, 179, 255);

    SDL_Surface* temp = SDL_LoadBMP("test_picture.bmp");
}
