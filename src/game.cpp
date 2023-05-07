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
    // SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0); // создали рендерер
    // if(renderer == NULL) spdlog::info("invalid renderer\n");

    
}
//--------------------------------------------------------------------------
void Game::Cleanup()
{
    SDL_Quit();
}
//--------------------------------------------------------------------------
int Game::Execute()
{

    // GameMap.OnRender(screen_surface, 0, 0);

    if(Init() == false) 
    {
        return INIT_ERROR;
    }

    // Render();

    

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
    if(SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS, &window, &renderer)) 
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
    Game::car_.init(0, 500, 500, 0, 500, 4, 800); 
    Game::car_.set_butons(SDL_SCANCODE_W, SDL_SCANCODE_S, SDL_SCANCODE_A, SDL_SCANCODE_D, SDL_SCANCODE_SPACE);

    Game::car_coordinates = Game::car_.get_coordinates();
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    car.w = 70;
    car.h = 40;
    car.x = Game::car_coordinates.get_x();
    car.y = Game::car_coordinates.get_y();
    SDL_RenderFillRect(renderer, &car);
    SDL_RenderPresent(renderer);
    //--------Draw not changed map (only obstacles)---------------------------
    SDL_Event Event;

    Map GameMap;
    GameMap.OnLoad();

    int id = 0;

    SDL_Rect obstacles;
    obstacles.h = obstacles.w = TILE_SIZE;

    SDL_Rect points_1;
    points_1.h = points_1.w = TILE_SIZE;

    SDL_Rect points_2;
    points_2.h = points_2.w = TILE_SIZE;

    SDL_Rect points_3;
    points_3.h = points_3.w = TILE_SIZE;

    SDL_Rect finish;
    finish.h = finish.w = TILE_SIZE;   

    for(int y = 0; y < MAP_HEIGHT; y++) 
    {
        for(int x = 0; x < MAP_WIDTH; x++) 
        {
            int x_ = x * TILE_SIZE;
            int y_ = y * TILE_SIZE; //Пусть пока что MapX и MapY = 0

            if(GameMap.TileList[id].TileType == TILE_TYPE_NONE)
            {
                id++;
                continue;
            }
            spdlog::info("x = {}, y = {}, id = {}, Type = {}", x, y, id, GameMap.TileList[id].TileType);

            if(GameMap.TileList[id].TileType == TILE_TYPE_OBSTACLES)
            {
                obstacles.x = x_;
                obstacles.y = y_;

                SDL_SetRenderDrawColor(renderer, 100, 255, 100, 255);
                SDL_RenderFillRect(renderer, &obstacles);
                
                // id++;
            }          
            id++;            
        }
        id++;
    }
    SDL_RenderPresent(renderer);

    //------------------------------------------------------------------------------------
    while(Running) 
    {
        while(SDL_PollEvent(&Event)) //проверяем события и передаем их по одному в OnEvent
        {
            OnEvent(&Event);
        }
        //---------ОТРИСОВКА МАШИНЫ + ДВИЖЕНИЕ---------------
        // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        // SDL_RenderClear(renderer);

        Game::car_coordinates = Game::car_.get_coordinates();

        car.x = Game::car_coordinates.get_x();
        car.y = Game::car_coordinates.get_y();
        Game::car_.move();

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &car);
        SDL_RenderPresent(renderer);
        SDL_Delay(8);
        //---------ОТРИСОВКА КАРТЫ---------------------------
        for(int y = 0; y < MAP_HEIGHT; y++) 
        {
            for(int x = 0; x < MAP_WIDTH; x++) 
            {
                int x_ = x * TILE_SIZE;
                int y_ = y * TILE_SIZE; //Пусть пока что MapX и MapY = 0

                if(GameMap.TileList[id].TileType == TILE_TYPE_NONE)
                {
                    continue;
                }

                if(GameMap.TileList[id].TileType == TILE_TYPE_OBSTACLES)
                {
                    obstacles.x = x_;
                    obstacles.y = y_;

                    SDL_SetRenderDrawColor(renderer, 100, 255, 100, 255);
                    SDL_RenderFillRect(renderer, &obstacles);
                    
                }          
                id++;
            }
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(8);
    }
    
    //------------------------------------------------------------------------
    return true;
}
//--------------------------------------------------------------------------
// void Game::Loop()
// {    

// }

//--------------------------------------------------------------------------
// SDL_Renderer* Game::get_render(SDL_Renderer* renderer)
// { 
//     return SDL_CreateRenderer(window, -1, 0);
// }
//--------------------------------
// Мне:
//  камера карта
//  порядок в коде
//  вращение текстуры

// очки на экран и базу данных
//--------------------------------
