#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <SDL.h>
// #include <SDL2.h>
// #include <SDL2/SDL_image.h>

class sdl
{
 public:
    SDL_Window   *window   = nullptr;
    SDL_Renderer *renderer = nullptr;
    sdl();
    ~sdl();
};

class window
{
 public:
    window();
    void loop(SDL_Renderer *renderer);
};
#endif //WIND0W_H