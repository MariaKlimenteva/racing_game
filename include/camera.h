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
    friend class Game;

    private:
    int MapX;
    int MapY;

    public:
    Camera();
    std::pair<int,int> SetPos(int x, int y);
};
//--------------------------------------------------------------------------
#endif //CAMERA_H