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
    private:
    std::vector<Tile> TileList;                                         //хранит список всех плиток карты                                                     
    
    public:
    Map();
    SDL_Surface* Surf_Tileset;
    bool OnLoad(char* File);                                            //загружает карту из файла и заполняет список плиток
    void OnRender(SDL_Surface* Surf_Display, int MapX, int MapY);       //рисует карту на экран и размещает все плитки на их места
                                                                        //MapX, MapY указывают, где отображать карту на экране 
};
//--------------------------------------------------------------------------
#endif // MAP_H