#ifndef MAP_H
#define MAP_H

#include <SDL.h>
#include <vector>
#include <spdlog/spdlog.h>

#include "tile.h"
#include "define.h"
//--------------------------------------------------------------------------
class Map
{
    friend class Game;

    private:
    std::vector<Tile> TileList;                                         //хранит список всех плиток карты                                                     
    SDL_Renderer*     renderer;

    public:
    Map();
    bool OnLoad();                                            //загружает карту из файла и заполняет список плиток
};
//--------------------------------------------------------------------------
#endif // MAP_H