#include <spdlog/spdlog.h>

#include "camera.h"
#include "define.h"
//--------------------------------------------------------------------------
Camera::Camera()
{
    MapX = 0;
    MapY = 0;
}
//--------------------------------------------------------------------------
// std::pair<int,int> Camera::SetPos(int x, int y) 
// {
//     std::pair<int, int> map_coordinates;
//     MapX = x;
//     MapY = y;
//     map_coordinates.first = MapX;
//     map_coordinates.second = MapY;

//     return map_coordinates;    
// }
//--------------------------------------------------------------------------
