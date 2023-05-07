#ifndef AREA_H
#define AREA_H

#include "map.h"
//--------------------------------------------------------------------------
class Area
{
    private:
    int AreaSize;
    SDL_Surface* Surf_Tileset;

    public:
    Area();

    std::vector<Map> MapList;
    static Area AreaControl;
     
    bool    OnLoad(char* File);
    void    OnRender(SDL_Surface* Surf_Display, int CameraX, int CameraY);
    void    OnCleanup();
};
//--------------------------------------------------------------------------
#endif //AREA_H