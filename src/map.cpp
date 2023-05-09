#include "map.h"
#include "game.h"

#include <iostream>
#include <fstream>
#include <cstdio>
//--------------------------------------------------------------------------
Map::Map()
{
    Game Game_;
}
//--------------------------------------------------------------------------
bool Map::OnLoad()
{
    TileList.clear(); //очищает вектор, чтоб можно было несколько раз загружать карту не думая о том что было до этого

    std::ifstream file;  // поток для чтения
    file.open("Map.txt");

    if(!file)
    {
        spdlog::error("Problems with opening a file. Try to run from root holder\n");
        perror("Map.txt");
        return false;
    }
    Tile TempTile;
    for (int i = 1; i <= MAP_WIDTH * MAP_HEIGHT; i++)
    {
        TempTile.TileID = i;
        file >> TempTile.TileType;

        TileList.push_back(TempTile);
    }
    
    file.close();
    return true;
}
