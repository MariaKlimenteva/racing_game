#ifndef CAMERA_H
#define CAMERA_H

#include "define.h"

#include <SDL.h>
//--------------------------------------------------------------------------
class Camera 
{
    private:
    int X;
    int Y;
    int* TargetX;
    int* TargetY;

    public:
    static Camera CameraControl;
    int TargetMode;
    
    Camera();
    void Move(int MoveX, int MoveY);
    int GetX();
    int GetY();
    void SetPos(int X, int Y);
    void SetTarget(int* X, int* Y);
};
//--------------------------------------------------------------------------
#endif //CAMERA_H