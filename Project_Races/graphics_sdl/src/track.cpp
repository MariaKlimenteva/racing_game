#include "track.h"

#include <iostream>

Map::Map()
{
    Surf_Tileset = NULL;
}

bool Map::OnLoad(char* File)
{
    TileList.clear(); //очищает вектор, чтоб можно было несколько раз загружать карту не думая о том что было до этого

    FILE* FileHandle = fopen(File, "r");
    if (FileHandle == NULL)
    {
        return false;
    }

    for(int y = 0; y < MAP_HEIGHT; y++)
    {
        for(int x = 0; x < MAP_WIDTH; x++)
        {
            Tile TempTile;
            fscanf(FileHandle, "%d:%d", &TempTile.TileID, &TempTile.TileType);
            TileList.push_back(TempTile);
        }
        fscanf(FileHandle, "\n");
    }
    fclose(FileHandle);
    
    return true;
}

void Map::OnRender(SDL_Surface* Surf_Display, int MapX, int MapY)
{

}
