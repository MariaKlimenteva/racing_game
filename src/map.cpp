#include "map.h"

#include <iostream>
//--------------------------------------------------------------------------
Map::Map()
{
    Surf_Tileset = NULL;
}
//--------------------------------------------------------------------------
bool Map::OnLoad(char* File)
{
    TileList.clear(); //очищает вектор, чтоб можно было несколько раз загружать карту не думая о том что было до этого

    FILE* FileHandle = fopen("Map.txt", "r");
    if (FileHandle == NULL)
    {
        spdlog::error("Problems with opening a file\n");
        return false;
    }

    for(int y = 0; y < MAP_HEIGHT; y++)
    {
        for(int x = 0; x < MAP_WIDTH; x++)
        {
            Tile TempTile;
            fscanf(FileHandle, "%d:%d", &TempTile.TileID, &TempTile.TileType); //заполняем TileID, TileType
            TileList.push_back(TempTile);
        }
        fscanf(FileHandle, "\n");
    }
    fclose(FileHandle);
    spdlog::info("The game map file has been read\n");
    return true;
}
//--------------------------------------------------------------------------
void Map::OnRender(SDL_Surface* Surf_Display, int MapX, int MapY) 
{
    if(Surf_Tileset == NULL) return;
 
    int TilesetWidth  = Surf_Tileset->w / TILE_SIZE;
    int TilesetHeight = Surf_Tileset->h / TILE_SIZE;
 
    int ID = 0;
 
    for(int Y = 0; Y < MAP_HEIGHT; Y++) 
    {
        for(int X = 0; X < MAP_WIDTH; X++) 
        {
            if(TileList[ID].TileType == TILE_TYPE_NONE) //проверка, надо ли рисовать эту плитку
            {
                ID++;
                continue;
            }
 
            int tX = MapX + (X * TILE_SIZE);
            int tY = MapY + (Y * TILE_SIZE);
 
            int TilesetX = (TileList[ID].TileID % TilesetWidth) * TILE_SIZE; // идентификатор плитки преобразуем в ее координату
            int TilesetY = (TileList[ID].TileID / TilesetWidth) * TILE_SIZE;

            // что то для отображения
            
 
            ID++;
        }
    }
}
//--------------------------------------------------------------------------