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
    Running                     = true;
    SDL_Window *window          = nullptr;
    SDL_Renderer* renderer      = nullptr;
    SDL_Surface* screen_surface = nullptr;

    obstacles.h = obstacles.w = TILE_SIZE;
    points_1.h = points_1.w = TILE_SIZE;
    points_2.h = points_2.w = TILE_SIZE;
    points_3.h = points_3.w = TILE_SIZE;
    finish.h = finish.w = TILE_SIZE; 
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
    int id = 0;
    Map GameMap;
    GameMap.OnLoad();
    //--------------------------------------------------------
    Game::car_coordinates = Game::car_.get_coordinates();
    SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
    car.w = 70;
    car.h = 40;
    car.x = Game::car_coordinates.get_x();
    car.y = Game::car_coordinates.get_y();
    SDL_RenderFillRect(Game::renderer, &car);
    SDL_RenderPresent(Game::renderer);
    //---------------------------------------------------------
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

            if(GameMap.TileList[id].TileType == TILE_TYPE_OBSTACLES)
            {
                obstacles.x = x_;
                obstacles.y = y_;

                SDL_SetRenderDrawColor(Game::renderer, 100, 255, 100, 255);
                SDL_RenderFillRect(Game::renderer, &obstacles);
            }  

            if(GameMap.TileList[id].TileType == TILE_TYPE_CHECKPOINT_1)
            {
                points_1.x = x_;
                points_1.y = y_;

                SDL_SetRenderDrawColor(Game::renderer, 255, 255, 0, 255);
                SDL_RenderFillRect(Game::renderer, &points_1);
                SDL_RenderPresent(Game::renderer);
            }

            if(GameMap.TileList[id].TileType == TILE_TYPE_CHECKPOINT_2)
            {
                points_2.x = x_;
                points_2.y = y_;

                SDL_SetRenderDrawColor(Game::renderer, 0, 0, 255, 255);
                SDL_RenderFillRect(Game::renderer, &points_2);
                SDL_RenderPresent(Game::renderer);
            }

            if(GameMap.TileList[id].TileType == TILE_TYPE_CHECKPOINT_3)
            {
                points_3.x = x_;
                points_3.y = y_;

                SDL_SetRenderDrawColor(Game::renderer, 255, 0, 255, 255);
                SDL_RenderFillRect(Game::renderer, &points_3);
                SDL_RenderPresent(Game::renderer);
            }

            if(GameMap.TileList[id].TileType == TILE_TYPE_FINISH)
            {
                finish.x = x_;
                finish.y = y_;

                SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 255);
                SDL_RenderFillRect(Game::renderer, &finish);
                SDL_RenderPresent(Game::renderer);
            }

            id++;            
        }
        
    }
    SDL_RenderPresent(Game::renderer);
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
    Map GameMap;
    GameMap.OnLoad();

    SDL_Event Event;

    Render();
    while(Running) 
    {
        while(SDL_PollEvent(&Event)) //проверяем события и передаем их по одному в OnEvent
        {
            OnEvent(&Event);
        }

        Loop(0);
    
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
    //-----------Создание и отображение окна---------------------------------
    if(SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS, &window, &(Game::renderer))) 
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

    return true;
}
//--------------------------------------------------------------------------
void Game::Loop(int id)
{    
        Map GameMap;
        GameMap.OnLoad();
        //---------ОТРИСОВКА МАШИНЫ + ДВИЖЕНИЕ---------------
        // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        // SDL_RenderClear(renderer);

        Game::car_coordinates = Game::car_.get_coordinates();

        car.x = Game::car_coordinates.get_x();
        car.y = Game::car_coordinates.get_y();
        Game::car_.move();

        SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(Game::renderer, &car);
        SDL_RenderPresent(Game::renderer);
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

                    SDL_SetRenderDrawColor(Game::renderer, 100, 255, 100, 255);
                    SDL_RenderFillRect(Game::renderer, &obstacles);
                }  

                if(GameMap.TileList[id].TileType == TILE_TYPE_CHECKPOINT_1)
                {
                    points_1.x = x_;
                    points_1.y = y_;

                    SDL_SetRenderDrawColor(Game::renderer, 255, 255, 0, 255);
                    SDL_RenderFillRect(Game::renderer, &points_1);
                    SDL_RenderPresent(Game::renderer);
                } 

                if(GameMap.TileList[id].TileType == TILE_TYPE_CHECKPOINT_2)
                {
                    points_2.x = x_;
                    points_2.y = y_;

                    SDL_SetRenderDrawColor(Game::renderer, 0, 0, 255, 255);
                    SDL_RenderFillRect(Game::renderer, &points_2);
                    SDL_RenderPresent(Game::renderer);
                }   

                if(GameMap.TileList[id].TileType == TILE_TYPE_CHECKPOINT_3)
                {
                    points_3.x = x_;
                    points_3.y = y_;

                    SDL_SetRenderDrawColor(Game::renderer, 255, 0, 255, 255);
                    SDL_RenderFillRect(Game::renderer, &points_3);
                    SDL_RenderPresent(Game::renderer);
                }

                if(GameMap.TileList[id].TileType == TILE_TYPE_FINISH)
                {
                    finish.x = x_;
                    finish.y = y_;

                    SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 255);
                    SDL_RenderFillRect(Game::renderer, &finish);
                    SDL_RenderPresent(Game::renderer);
                }

                id++;
            }
        }
        SDL_RenderPresent(Game::renderer);

        // Game::Render();
        SDL_Delay(8);
}
//--------------------------------
// Мне:
//  камера карта
//  порядок в коде
//  вращение текстуры

// очки на экран и базу данных
//--------------------------------
