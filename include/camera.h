#ifndef CAMERA_H
#define CAMERA_H
//--------------------------------------------------------------------------
#include <utility>

#include "car.h"
//--------------------------------------------------------------------------
class car_t;
class coordinates_t;

class Camera
{
    private:
    int MapX;
    int MapY;

    int x;
    int y;

    public:
    Camera();
    // std::pair<int,int> Move(int MoveX, int MoveY);
    std::pair<int,int> SetPos(int x, int y);
    // void CameraMove(car_t& car_, coordinates_t& car_coordinates, int x, int y);
};
//--------------------------------------------------------------------------
#endif //CAMERA_H