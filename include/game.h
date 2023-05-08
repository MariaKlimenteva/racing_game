#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <spdlog/spdlog.h>

#include "define.h"
#include "car.h"

//--------------------------------------------------------------------------
class Map;

class Game
{
    friend class Map;
    friend class Texture;

    private:
    bool             Running;
    bool             redraw;

    SDL_Window*      window;
    SDL_Renderer*    renderer;
    SDL_Surface*     screen_surface;
    
    car_t            car_;
    coordinates_t    car_coordinates;

    SDL_Rect obstacles;
    SDL_Rect points_1;
    SDL_Rect points_2;
    SDL_Rect points_3;
    SDL_Rect finish;
    SDL_Rect redrawed;

    public:
    Game();

    int  Execute(); //выполняет основной цикл игры 
    bool Init();    //Инициализация игры и в том числе используемой библиотеки
    void OnEvent(SDL_Event* Event); //обработка событий (любое нажатие клавиш, мышки и тп)
    void Loop(Map& GameMap);
    void Render(Map& GameMap);
    void Cleanup();
    void MapRender(int id, Map& GameMap);
    void CarRender();
    // void OnKeyDown(SDL_KeyCode sym, Uint16 unicode); //для перемещения камеры
};
//--------------------------------------------------------------------------
#endif