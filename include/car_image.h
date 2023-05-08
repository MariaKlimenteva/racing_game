#ifndef CAR_IMAGE_H
#define CAR_IMAGE_H
 
#include <SDL.h>
#include <SDL_image.h>

#include <string>

#include "game.h"

class Texture 
{
    friend class Game;
    public:
    Texture();
 
    public:
    SDL_Texture* LoadImage(const std::string& file, SDL_Renderer* ren);
    void RenderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);
};
 
#endif //CAR_IMAGE_H