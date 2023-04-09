#ifndef GAME_H
#define GAME_H

#include <SDL.h>

#include "define.h"

//--------------------------------------------------------------------------

class Game
{
    private:
    bool            Running;
    SDL_Surface*    Surf_Display;

    public:
    Game();
    int  Execute(); //выполняет основной цикл игры 
    bool Init(); //Инициализация игры и в том числе используемой библиотеки
    void OnEvent(SDL_Event* Event);
    void Loop();
    void Render();
    void Cleanup();
};

//--------------------------------------------------------------------------

#endif