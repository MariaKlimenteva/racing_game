#ifndef GAME_H
#define GAME_H

#include <SDL.h>

#include "surface.h"
#include "define.h"
// #include "area.h"
// #include "camera.h"
//--------------------------------------------------------------------------
class Game
{
    private:
    bool            Running;
    SDL_Surface*    Surf_Display;
    SDL_Surface*    Surf_Test; // сoздали тестовую поверхность чтоб проверить, работает ли

    public:
    Game();

    int  Execute(); //выполняет основной цикл игры 
    bool Init();    //Инициализация игры и в том числе используемой библиотеки
    void OnEvent(SDL_Event* Event); //обработка событий (любое нажатие клавиш, мышки и тп)
    void Loop();
    void Render();
    void Cleanup();
    void OnKeyDown(SDL_KeyCode sym, Uint16 unicode); //для перемещения камеры
};
//--------------------------------------------------------------------------
#endif