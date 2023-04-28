#include <iostream>
// #include <SDL2/SDL_image.h>

#include "game.h"
#include "map.h"
#include "define.h"
//--------------------------------------------------------------------------
// Constructor
//--------------------------------------------------------------------------
Game::Game()
{
    Surf_Test = NULL; //тестовая поверхность
    Surf_Display = NULL;
    Running = true;
}
//--------------------------------------------------------------------------
// Обработка событий, происходящих во время игры (Нажатие кнопки выход из игры, ...)
//--------------------------------------------------------------------------
void Game::OnEvent(SDL_Event* Event) 
{
    spdlog::info("OnEvent::{} {}", Event->type, SDL_QUIT);
    if(Event->type == SDL_QUIT) //4196274163 256
    {
        Running = false;
        spdlog::info("!!! \n");
        SDL_Quit();
    }
}
//--------------------------------------------------------------------------
// void Game::OnKeyDown(SDL_KeyCode sym, Uint16 unicode) 
// {
//     switch(sym) 
//     {
//         case SDLK_UP:    Camera::CameraControl.Move( 0,  5); break;
//         case SDLK_DOWN:  Camera::CameraControl.Move( 0, -5); break;
//         case SDLK_LEFT:  Camera::CameraControl.Move( 5,  0); break;
//         case SDLK_RIGHT: Camera::CameraControl.Move(-5,  0); break;
 
//         default: {}
//     }
// }
//--------------------------------------------------------------------------
void Game::Loop()
{

}
//--------------------------------------------------------------------------
void Game::Render()
{
    Surface::Draw(Surf_Display, Surf_Test, 0, 0);
}
//--------------------------------------------------------------------------
void Game::Cleanup()
{
    SDL_FreeSurface(Surf_Test);
    SDL_FreeSurface(Surf_Display);

    SDL_Quit();
}
//--------------------------------------------------------------------------
int Game::Execute()
{
    if(Init() == false) 
    {
        return INIT_ERROR;
    }
 
    SDL_Event Event;
 
    while(Running) 
    {
        while(SDL_PollEvent(&Event)) //проверяем события и передаем их по одному в OnEvent
        {
            OnEvent(&Event);
        }

        Loop();
        Render();
    }
 
    Cleanup();
 
    exit(EXIT_SUCCESS);
}
//--------------------------------------------------------------------------
bool Game::Init()
{
    //-----------Инициализация SDL------------------------------------------
    if(SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        return false;
    }

    SDL_Window *window          = nullptr;
    SDL_Renderer *renderer      = nullptr;
    SDL_Surface *screen_surface = nullptr;
    //-----------Создание и отображение окна---------------------------------
    if (SDL_CreateWindowAndRenderer(1024, 768, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS, &window, &renderer)) 
    {
        std::cerr << "Failed to create window and renderer: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    SDL_SetWindowTitle(window, "Races");
    //------------Создание поверхности, связанной с окном и раскрашивание окна---------------------
    screen_surface = SDL_GetWindowSurface(window);

    if (!screen_surface) 
    {
        std::cerr << "Screen surface could not be created: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }
    SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 255, 255, 255));
    SDL_UpdateWindowSurface(window);
    // ------------Карта-------------------------------------------------------

    // ------------Картинка машинки-------------------------------------------------------
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
    SDL_Rect car = {50, 50, 50, 50};
    SDL_RenderFillRect(renderer, &car);
    SDL_RenderPresent(renderer);
    
    return true;
}

