#include "map.h"
#include "game.h"

#include <iostream>
#include <fstream>
#include <cstdio>
//--------------------------------------------------------------------------
Map::Map()
{
    Game Game_;
    // SDL_Renderer* renderer = Game_.get_render(renderer);
}
//--------------------------------------------------------------------------
bool Map::OnLoad()
{
    TileList.clear(); //очищает вектор, чтоб можно было несколько раз загружать карту не думая о том что было до этого

    std::ifstream file;  // поток для чтения
    file.open("Map.txt");

    if(!file)
    {
        spdlog::error("Problems with opening a file\n");
        perror("Map.txt");
        return false;
    }
    Tile TempTile;
    for (int i = 1; i <= MAP_WIDTH * MAP_HEIGHT; i++)
    {
        TempTile.TileID = i;
        file >> TempTile.TileType;

        TileList.push_back(TempTile);

        // if ((TempTile.TileID <= 40) || (TempTile.TileID >= 1600 - 40)) spdlog::info("{} {}", TempTile.TileID, TempTile.TileType);
    }


    file.close();
    spdlog::info("The game map file has been read\n");
    return true;
}
//--------------------------------------------------------------------------
// void Map::OnRender(SDL_Surface* screen_surface, int MapX, int MapY) 
// {
    // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    // SDL_RenderClear(renderer);

    // for (int x = 90; x <= 1000; x += 150)
    // {
    //     for (int y = 90; y <= 1000; y += 150)
    //     {
    //         obstacles.x = x;
    //         obstacles.y = y;
    //         SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    //         SDL_RenderFillRect(renderer, &obstacles);
    //         SDL_RenderPresent(renderer);
    //     }
    // }
    // SDL_Delay(10);
    
//     int id = 0;
 
//     for(int y = 0; y < MAP_HEIGHT; y++) 
//     {
//         for(int x = 0; x < MAP_WIDTH; x++) 
//         {
//             if(TileList[id].TileType == TILE_TYPE_NONE) //проверка, надо ли рисовать эту плитку
//             {
//                 id++;
//                 continue;
//             }
 
//             int x_ = MapX + (x * TILE_SIZE);
//             int y_ = MapY + (y * TILE_SIZE);

//             obstacles.x = 30;
//             obstacles.y = 30;
            
//             SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
//             SDL_RenderFillRect(renderer, &obstacles);
//             SDL_RenderPresent(renderer);
            
//             id++;
//         }
//     }
// }
//--------------------------------------------------------------------------


// std::vector<Tile> Map::
// {
//     return; 
// }