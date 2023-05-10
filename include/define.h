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
    WINDOW_WIDTH      = 2*AREA_SIZE + TILE_SIZE,
    WINDOW_HEIGHT     = 2*AREA_SIZE + TILE_SIZE
};
//--------------------------------------------------------------------------
enum CarCharacteristics
{
    CAR_WIDTH  = 50,
    CAR_HEIGHT = 70,
    CAR_INIT_X = 20,
    CAR_INIT_Y = 550
};
//--------------------------------------------------------------------------
enum Inaccuracy
{
    X_ERROR      = 30,
    Y_ERROR      = 20,
    POINTS_ERROR = TILE_SIZE,
};
//--------------------------------------------------------------------------
enum VisablePart
{
    MIN_MAP_X = -568,
    MIN_MAP_Y = -570
};
//--------------------------------------------------------------------------
#endif //DEFINE_H