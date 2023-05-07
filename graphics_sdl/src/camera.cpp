#include "camera.h"
//--------------------------------------------------------------------------
Camera Camera::CameraControl;
//--------------------------------------------------------------------------
Camera::Camera() 
{
    X = Y = 0;
    TargetX = TargetY = NULL;
    TargetMode = TargetMode::NORMAL;
}
//--------------------------------------------------------------------------
void Camera::Move(int MoveX, int MoveY) 
{
    X += MoveX;
    Y += MoveY;
}
//-------------------------------------------------------------------------- 
int Camera::GetX() 
{
    if(TargetX != NULL) 
    {
        if(TargetMode == TargetMode::CENTER) 
        {
            return *TargetX - (WINDOW_WIDTH / 2);
        }
        return *TargetX;
    }
    return X;
}
//--------------------------------------------------------------------------
int Camera::GetY() 
{
    if(TargetY != NULL) 
    {
        if(TargetMode == TargetMode::CENTER) 
        {
            return *TargetY - (WINDOW_HEIGHT / 2);
        }
        return *TargetY;
    }
    return Y;
}
//--------------------------------------------------------------------------
void Camera::SetPos(int X, int Y) 
{
    this->X = X;
    this->Y = Y;
}
//--------------------------------------------------------------------------
void Camera::SetTarget(int* X, int* Y)
{
    TargetX = X;
    TargetY = Y;
}
//--------------------------------------------------------------------------