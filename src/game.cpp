#include <iostream>

#include "game.h"
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
    if(Event->type == SDL_QUIT) 
    {
        Running = false;
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
    // Surface::Draw(Surf_Display, Surf_Test, 100, 100, 0, 0, 50, 50); Шаблонная функция (2)
    // Area::AreaControl.OnRender(Surf_Display, Camera::CameraControl.GetX(), Camera::CameraControl.GetY());


    // SDL_RendererFlip(Surf_Display); // ??????? мб не верно сделала, т к изменился стандарт библиотеки
}
//--------------------------------------------------------------------------
void Game::Cleanup()
{
    // Area::AreaControl.OnCleanup();
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
    SDL_SetRenderDrawColor(renderer, 210, 255, 179, 255);
    //------------Создание поверхности, связанной с окном---------------------
    screen_surface = SDL_GetWindowSurface(window);

    if (!screen_surface) 
    {
        std::cerr << "Screen surface could not be created: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }
    //------------Тестовая загрузка поверхности---------------------
    // if((Surf_Test = Surface::OnLoad("roadmarkings-14.jpg", window)) == NULL) //тестовая загрузка поверхности
    // {
    //     return false;
    // }

    /*if(!(Area::AreaControl.OnLoad("./maps/1.area"))) 
    {
        return false;
    }*/
 
    // SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3); 
    // ----------Дописать обработку клавиш с клавиатуры---------------

    return true;
}

