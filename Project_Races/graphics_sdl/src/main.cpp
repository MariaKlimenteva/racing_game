#include <iostream>
#include <SDL2/SDL.h>


// // int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int)
// // {
// // 	exit(EXIT_SUCCESS);
// // }

// int main()
// {
//     SDL_Init(0);
//     SDL_Quit();
    
//     return 0;
// }
// #include <iostream>
// #define SDL_MAIN_HANDLED
// #include <SDL.h>

void main_loop(SDL_Renderer *renderer) {
    while (1) { // main game loop
        SDL_Event event; // handle window closing
        if (SDL_PollEvent(&event) && (SDL_QUIT==event.type || (SDL_KEYDOWN==event.type && SDLK_ESCAPE==event.key.keysym.sym)))
            break; // quit
        SDL_RenderClear(renderer); // re-draw the window
        SDL_RenderPresent(renderer);
    }
}

int main() {
    SDL_SetMainReady(); // tell SDL that we handle main() function ourselves, comes with the SDL_MAIN_HANDLED macro
    if (SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Window   *window   = nullptr;
    SDL_Renderer *renderer = nullptr;
    if (SDL_CreateWindowAndRenderer(1024, 768, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS, &window, &renderer)) {
        std::cerr << "Failed to create window and renderer: " << SDL_GetError() << std::endl;
        return -1;
    }
    SDL_SetWindowTitle(window, "SDL2 game blank");
    SDL_SetRenderDrawColor(renderer, 210, 255, 179, 255);

    main_loop(renderer); // all interesting things happen here

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}