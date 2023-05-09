#include <iostream>
#include <cmath>

#include "game.h"
#include "map.h"
#include "define.h"
#include "car.h"
#include "car_image.h"
#include "camera.h"

//--------------------------------------------------------------------------
// Constructor
//--------------------------------------------------------------------------
Game::Game()
{
    Running                     = true;
    SDL_Window* window          = nullptr;
    SDL_Renderer* renderer      = nullptr;
    SDL_Surface* screen_surface = nullptr;

    obstacles.h = obstacles.w   = TILE_SIZE;
    points_1.h  = points_1.w    = TILE_SIZE;
    points_2.h  = points_2.w    = TILE_SIZE;
    points_3.h  = points_3.w    = TILE_SIZE;
    finish.h    = finish.w      = TILE_SIZE; 
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
void Game::Render(Map& GameMap, Camera& GameCamera, int camera_current_x, int camera_current_y, int car_x, int car_y)
{
    map_coordinates = GameCamera.SetPos(camera_current_x, camera_current_y);

    for(int x = 0; x <= 615; x++)
    { 
        // for(int y = 500; y >= -100; y++)
        // {
            if(car_coordinates.get_x() >= x)
            {
                map_coordinates = GameCamera.SetPos(-x, CAMERA_INIT_Y);
            }

            // if(car_coordinates.get_y() <= y)
            // {
            //     map_coordinates = GameCamera.SetPos(CAMERA_INIT_X, -y);
            // }
        // }

    }
spdlog::info("{}", car_coordinates.get_y());
    for(int y = 420; y >= 0; y--)
    {   
        if(car_coordinates.get_y() <= y)
        {
            map_coordinates = GameCamera.SetPos(CAMERA_INIT_X, -y);
        }
    }


    int MapX = map_coordinates.first;
    int MapY = map_coordinates.second;

    Game::CarRender();
    Game::MapRender(0, GameMap, MapX, MapY); 
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

    Camera GameCamera;

    int camera_current_x = CAMERA_INIT_X;
    int camera_current_y = CAMERA_INIT_Y;

    int car_x = CAR_INIT_X;
    int car_y = CAR_INIT_Y;

    SDL_Event Event;

    Render(GameMap, GameCamera, camera_current_x, camera_current_y, car_x, car_y);

    while(Running) 
    {
        while(SDL_PollEvent(&Event)) //проверяем события и передаем их по одному в OnEvent
        {
            OnEvent(&Event);
        }
        Loop(GameMap, GameCamera, camera_current_x, camera_current_y, car_x, car_y);
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
    Game::car_.init(0, CAR_INIT_X, CAR_INIT_Y, 0, 500, 4, 800); 
    Game::car_.set_butons(SDL_SCANCODE_W, SDL_SCANCODE_S, SDL_SCANCODE_A, SDL_SCANCODE_D, SDL_SCANCODE_SPACE);

    return true;
}
//--------------------------------------------------------------------------
void Game::Loop(Map& GameMap, Camera& GameCamera, int camera_current_x, int camera_current_y, int car_x, int car_y)
{    
        //---------ОТРИСОВКА МАШИНЫ и КАРТЫ + ДВИЖЕНИЕ---------------
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        Game::Render(GameMap, GameCamera, camera_current_x, camera_current_y, car_x, car_y);
        Game::car_.move();
        SDL_Delay(1);
}
//--------------------------------------------------------------------------
void Game::MapRender(int id, Map& GameMap, int MapX, int MapY)
{
    for(int y = 0; y < MAP_HEIGHT; y++) 
    {
        for(int x = 0; x < MAP_WIDTH; x++) 
        {
            int x_ = MapX + (x * TILE_SIZE);
            int y_ = MapY + (y * TILE_SIZE); //Пусть пока что MapX и MapY = 0

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

                Game::CollectPoints(points_1, id, GameMap);
            } 

            if(GameMap.TileList[id].TileType == TILE_TYPE_CHECKPOINT_2)
            {
                points_2.x = x_;
                points_2.y = y_;

                SDL_SetRenderDrawColor(Game::renderer, 0, 0, 255, 255);
                SDL_RenderFillRect(Game::renderer, &points_2);

                Game::CollectPoints(points_2, id, GameMap);
            }   

            if(GameMap.TileList[id].TileType == TILE_TYPE_CHECKPOINT_3)
            {
                points_3.x = x_;
                points_3.y = y_;

                SDL_SetRenderDrawColor(Game::renderer, 255, 0, 255, 255);
                SDL_RenderFillRect(Game::renderer, &points_3);

                Game::CollectPoints(points_3, id, GameMap);
            }

            if(GameMap.TileList[id].TileType == TILE_TYPE_FINISH)
            {
                finish.x = x_;
                finish.y = y_;

                SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 255);
                SDL_RenderFillRect(Game::renderer, &finish);
            }

            id++;
        }
    }
    SDL_RenderPresent(Game::renderer);
}
//--------------------------------------------------------------------------
void Game::CarRender()
{
    Game::car_coordinates = Game::car_.get_coordinates();

    // if((obstacles.x <= car_coordinates.get_x() <= obstacles.x + TILE_SIZE) || (obstacles.y <= car_coordinates.get_y() <= obstacles.y + TILE_SIZE))
    // {
    //     double direction = car_coordinates.get_direction();
    //     car_coordinates.change_direction(direction--);
    // }

    Texture image;
    SDL_Texture* car_texture = image.LoadImage("car_image.png", renderer);
    image.RenderTexture(car_texture, renderer, Game::car_coordinates.get_direction(), Game::car_coordinates.get_x(), Game::car_coordinates.get_y(), CAR_WIDTH, CAR_HEIGHT);
}
//--------------------------------------------------------------------------
void Game::CollectPoints(SDL_Rect points, int id, Map& GameMap)
{
    if(((points.x <= car_coordinates.get_x() + X_ERROR) && (car_coordinates.get_x() - X_ERROR <= points.x + POINTS_ERROR)) && ((points.y <= car_coordinates.get_y() + Y_ERROR) && (car_coordinates.get_y() - Y_ERROR <= points.y + POINTS_ERROR)))
    {
        GameMap.TileList[id].TileType = TILE_TYPE_NONE;
    }
}
//--------------------------------------------------------------------------
// void Game::CameraMove(int x, int y, Camera& GameCamera)
// {
//     if(car_coordinates.get_x() >= x)
//     {
//         map_coordinates = GameCamera.SetPos(-x, -CAMERA_INIT_Y);
        
//     }
// }
//--------------------------------------------------------------------------