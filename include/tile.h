#ifndef TILE_H
#define TILE_H
//--------------------------------------------------------------------------
enum
{
    TILE_TYPE_NONE = 0,
    TILE_TYPE_OBSTACLES = 1,
    TILE_TYPE_CHECKPOINT_1 = 2,
    TILE_TYPE_CHECKPOINT_2 = 3,
    TILE_TYPE_CHECKPOINT_3 = 4,
    TILE_TYPE_FINISH = 5
};
//--------------------------------------------------------------------------
class Tile
{
    public:
    Tile(): TileID(0), TileType(TILE_TYPE_NONE){};
    int TileID; //индивидуальное число для каждой клетки
    int TileType; //1 - клетка занята, 0 - нет
};
//--------------------------------------------------------------------------
//карта в формате текстового файла, состоит из клеток, каждая клетка хранит два значения - ее занятость и тип клетки
//--------------------------------------------------------------------------
#endif // TILE_H

// 0 - ничего не рисуем - черный
// 1 - стенка - зеленый
// 2 - чекпоин 2 очка - желтый
// 3 - чекпоинт 3 очка - синий
// 4 - самый дорогой чекпоинт - фиолетовый
// 5 - старт и финиш - красный