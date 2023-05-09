#ifndef DEFINE_H
#define DEFINE_H
//--------------------------------------------------------------------------
enum //возвращаемые коды ошибок
{
    INIT_ERROR      = 1
};
//--------------------------------------------------------------------------
enum Size
{
    TILE_SIZE         = 30,
    AREA_SIZE         = 300,
    MAP_WIDTH         = 40,
    MAP_HEIGHT        = 40,
    WINDOW_WIDTH      = 2*AREA_SIZE,
    WINDOW_HEIGHT     = 2*AREA_SIZE
};
//--------------------------------------------------------------------------
enum TargetMode
{
    NORMAL = 0,
    CENTER
};
//--------------------------------------------------------------------------
enum CameraPosition
{
    CAMERA_INIT_X = 0,
    CAMERA_INIT_Y = -600
};
//--------------------------------------------------------------------------
enum CarCharacteristics
{
    CAR_WIDTH  = 50,
    CAR_HEIGHT = 70,
    CAR_INIT_X = CAMERA_INIT_X + 40,
    CAR_INIT_Y = -CAMERA_INIT_Y - 100
};
//--------------------------------------------------------------------------
enum Inaccuracy
{
    X_ERROR      = 30,
    Y_ERROR      = 20,
    POINTS_ERROR = TILE_SIZE,
    VISIBLE_PART_X = WINDOW_WIDTH - CAR_WIDTH,
    VISIBLE_PART_Y = WINDOW_WIDTH - CAR_HEIGHT
};
//--------------------------------------------------------------------------
#endif //DEFINE_H