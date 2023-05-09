#ifndef TILE_H
#define TILE_H
//--------------------------------------------------------------------------
enum
{
    TILE_TYPE_NONE          = 0,
    TILE_TYPE_OBSTACLES     = 1,
    TILE_TYPE_CHECKPOINT_1  = 2,
    TILE_TYPE_CHECKPOINT_2  = 3,
    TILE_TYPE_CHECKPOINT_3  = 4,
    TILE_TYPE_FINISH        = 5
};
//--------------------------------------------------------------------------
class Tile
{
    public:
    Tile(): TileID(0), TileType(TILE_TYPE_NONE){};
    int TileID; //индивидуальное число для каждой клетки
    int TileType; 
};
//--------------------------------------------------------------------------
#endif // TILE_H