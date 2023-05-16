#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <spdlog/spdlog.h>

#include "define.h"
#include "car.h"

// --------------------------------------------------------------------------
class Map;
class Camera;

class Game
{
    friend class Map;
    friend class Texture;
    friend class Camera;

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

    std::pair<int, int> map_coordinates;

    public:
    Game();

    int  Execute(); //выполняет основной цикл игры 
    bool Init();    //Инициализация игры и в том числе используемой библиотеки
    void OnEvent(SDL_Event* Event); //обработка событий (любое нажатие клавиш, мышки и тп)
    void Loop(Map& GameMap, Camera& GameCamera);
    void Render(Map& GameMap, Camera& GameCamera);
    void Cleanup();
    void MapRender(Map& GameMap, int MapX, int MapY);
    void CarRender();
    void CollectPoints(SDL_Rect points, int id, Map& GameMap);
    bool IsWall(Map& GameMap, int id, coordinates_t coordinates);
};
//--------------------------------------------------------------------------
#endif