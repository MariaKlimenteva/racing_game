#include <spdlog/spdlog.h>

#include "camera.h"
#include "define.h"
//--------------------------------------------------------------------------
Camera::Camera()
{
    MapX = 0;
    MapY = -600;
    x = y = 0;
}
//--------------------------------------------------------------------------
std::pair<int, int> Camera::Move(int MoveX, int MoveY) 
{
    x += MoveX;
    y += MoveY;
    std::pair<int, int> new_coordinates;
    new_coordinates.first = x;
    new_coordinates.second = y;

    return (new_coordinates);
}
//--------------------------------------------------------------------------
std::pair<int,int> Camera::SetPos(int x, int y) 
{
    std::pair<int, int> map_coordinates;
    MapX = x;
    MapY = y;
    map_coordinates.first = MapX;
    map_coordinates.second = MapY;

    return map_coordinates;    
}
//--------------------------------------------------------------------------