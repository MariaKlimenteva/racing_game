#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <spdlog/spdlog.h>

#include "define.h"
#include "car.h"

//--------------------------------------------------------------------------
class Game
{
    friend class Map;

    private:
    bool             Running;
    SDL_Window*      window;
    SDL_Renderer*    renderer;
    SDL_Surface*     screen_surface;
    SDL_Rect         car;
    
    car_t            car_;
    coordinates_t    car_coordinates;

    SDL_Rect obstacles;
    SDL_Rect points_1;
    SDL_Rect points_2;
    SDL_Rect points_3;
    SDL_Rect finish;

    public:
    Game();

    int  Execute(); //выполняет основной цикл игры 
    bool Init();    //Инициализация игры и в том числе используемой библиотеки
    void OnEvent(SDL_Event* Event); //обработка событий (любое нажатие клавиш, мышки и тп)
    void Loop(int id);
    void Render();
    void Cleanup();
    // void OnKeyDown(SDL_KeyCode sym, Uint16 unicode); //для перемещения камеры
};
//--------------------------------------------------------------------------
#endif