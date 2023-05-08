#ifndef DEFINE_H
#define DEFINE_H
//--------------------------------------------------------------------------
enum //возвращаемые коды ошибок
{
    INIT_ERROR      = 1,
};
//--------------------------------------------------------------------------
enum Size
{
    TILE_SIZE         = 30,
    MAP_WIDTH         = 40,
    MAP_HEIGHT        = 40,
    WINDOW_WIDTH      = MAP_WIDTH * TILE_SIZE,
    WINDOW_HEIGHT     = MAP_HEIGHT * TILE_SIZE,
};
//--------------------------------------------------------------------------
enum TargetMode
{
    NORMAL = 0,
    CENTER
};
//--------------------------------------------------------------------------
enum Inaccuracy
{
    X_ERROR      = 30,
    Y_ERROR      = 20,
    POINTS_ERROR = TILE_SIZE
};
//--------------------------------------------------------------------------
#endif //DEFINE_H