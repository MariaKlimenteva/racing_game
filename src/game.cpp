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
    SDL_Surface* Surf_Display   = nullptr;
    Running                     = true;
    SDL_Window *window          = nullptr;
    SDL_Renderer* renderer      = nullptr;
    SDL_Surface* screen_surface = nullptr;
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
        // Loop();
        // Render();
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
    car_t car_;
    car_.init(0, 500, 500, 0, 500, 4, 800); //window SDL 1024*768
    car_.set_butons(SDL_SCANCODE_W, SDL_SCANCODE_S, SDL_SCANCODE_A, SDL_SCANCODE_D, SDL_SCANCODE_SPACE);

    spdlog::info("successful initialization\n");

    //--------Draw not changed map (only obstacles)---------------------------
    obstacles.w = 20;
    obstacles.h = 20;
    
    for (int x = 90; x <= 1004; x += 150)
    {
        for (int y = 60; y <= 740; y += 100)
        {
            obstacles.x = x;
            obstacles.y = y;
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
            SDL_RenderFillRect(renderer, &obstacles);
            SDL_RenderPresent(renderer);
        }
    }

    while(1)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        coordinates_t car_coordinates = car_.get_coordinates();
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        car.w = 70;
        car.h = 40;
        car.x = car_coordinates.get_x();
        car.y = car_coordinates.get_y();
        car_.move();
        
        SDL_RenderFillRect(renderer, &car);
        
        

        for (int x = 90; x <= 1004; x += 150)
        {
            for (int y = 60; y <= 740; y += 100)
            {
                obstacles.x = x;
                obstacles.y = y;
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
                SDL_RenderFillRect(renderer, &obstacles);
                // SDL_RenderPresent(renderer);
            }
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(8);
    }

    
    // SDL_Rect points;
    // points.w = 2;
    // points.h = 1;

    // for ()
    //------------------------------------------------------------------------
    return true;
}
//--------------------------------------------------------------------------
void Game::Loop()
{
    // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    // SDL_RenderClear(renderer);

    // coordinates_t car_coordinates = car_.get_coordinates();
    // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    // car.w = 70;
    // car.h = 40;
    // car.x = car_coordinates.get_x();
    // car.y = car_coordinates.get_y();
    // car_.move();
    
    // SDL_RenderFillRect(renderer, &car);

    // for (int x = 90; x <= 1004; x += 150)
    // {
    //     for (int y = 60; y <= 740; y += 100)
    //     {
    //         obstacles.x = x;
    //         obstacles.y = y;
    //         SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
    //         SDL_RenderFillRect(renderer, &obstacles);
    //         // SDL_RenderPresent(renderer);
    //     }
    // }
    // SDL_RenderPresent(renderer);
    // SDL_Delay(8);

}
//камера карта
//порядок в коде
//очки на экран и базу данных
//вращение текстуры

