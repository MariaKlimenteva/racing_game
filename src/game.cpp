#include <iostream>

#include "game.h"
#include "map.h"
#include "define.h"
#include "car.h"

//--------------------------------------------------------------------------
// Constructor
//--------------------------------------------------------------------------
Game::Game()
{
    // Surf_Test = NULL; //тестовая поверхность
    Surf_Display                = NULL;
    Running                     = true;
    SDL_Window *window          = nullptr;
    SDL_Renderer *renderer      = nullptr;
    SDL_Surface *screen_surface = nullptr;
}
//--------------------------------------------------------------------------
// Обработка событий, происходящих во время игры (Нажатие кнопки выход из игры, ...)
//--------------------------------------------------------------------------
void Game::OnEvent(SDL_Event* Event) 
{
    if((Event->type) == SDL_QUIT)
    {
        Running = false;
        SDL_Quit();
    }
}
//--------------------------------------------------------------------------
void Game::Render()
{
    // ------------Картинка машинки-------------------------------------------------------
}
//--------------------------------------------------------------------------
void Game::Cleanup()
{
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
    // spdlog::info ("before cleanup\n");
    Cleanup();
    // spdlog::info("after cleanup\n");
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
    //---------Создание поверхности, связанной с окном и раскрашивание окна--
    screen_surface = SDL_GetWindowSurface(window);

    if (!screen_surface) 
    {
        std::cerr << "Screen surface could not be created: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }
    SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0, 0, 0)); // отвечает за цвет окна
    SDL_UpdateWindowSurface(window);
    //---------Car initialisation--------------------------------------------
    int prtime1 = 0, prtime2 = 0, timer = 0;
    car_t car_;
    car_.init(0, 0, 0, 0, 4, 4, 1);
    car_.set_butons(SDLK_w, SDLK_s, SDLK_a, SDLK_d, SDLK_SPACE);

    coordinates_t car_coordinates = car_.get_coordinates();
    spdlog::info("successful initialization\n");
    SDL_Rect car;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    car.x = car_coordinates.get_x();
    car.y = car_coordinates.get_y();
    car.w = 70;
    car.h = 40;

    SDL_RenderFillRect(renderer, &car);
    SDL_RenderPresent(renderer);

    return true;
}
//--------------------------------------------------------------------------
void Game::Loop()
{
    // ------------Карта-------------------------------------------------------
    // for(timer = clock(); 1; timer = clock())
    // {
    //     if((timer - prtime2) > CLOCKS_PER_SEC / 2) 
    //     {
    //         car_.get_coordinates().qprint();
    //         prtime2 = timer;
    //     }
    //     if((timer - prtime1) > CLOCKS_PER_SEC/100) 
    //     {
    //         car_.move();
    //         prtime1 = timer;
    //     }
    // }
    

}

