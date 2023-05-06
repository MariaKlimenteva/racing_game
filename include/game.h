#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <spdlog/spdlog.h>

#include "define.h"
#include "car.h"

//--------------------------------------------------------------------------
class Game
{
    private:
    bool             Running;
    SDL_Window*      window;
    SDL_Renderer*    renderer;
    SDL_Surface*     screen_surface;
    SDL_Rect         car;
    
    car_t            car_;
    coordinates_t    car_coordinates;

    public:
    Game();

    int  Execute(); //выполняет основной цикл игры 
    bool Init();    //Инициализация игры и в том числе используемой библиотеки
    void OnEvent(SDL_Event* Event); //обработка событий (любое нажатие клавиш, мышки и тп)
    void Loop();
    void Render();
    void Cleanup();
    void OnKeyDown(SDL_KeyCode sym, Uint16 unicode); //для перемещения камеры
    SDL_Renderer* get_render(SDL_Renderer*    renderer);
};
//--------------------------------------------------------------------------
#endif