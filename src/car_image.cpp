#include "car_image.h"
#include "game.h"
//--------------------------------------------------------------------------
Texture::Texture() {}
//--------------------------------------------------------------------------
// Загрузка поверхности
//--------------------------------------------------------------------------
SDL_Texture* Texture::LoadImage(const std::string& file, SDL_Renderer* ren)
{
	SDL_Texture *texture = IMG_LoadTexture(ren, file.c_str());
	if (!texture)
	{
        spdlog::info("{}", IMG_GetError());
	}
	return texture;
}
//--------------------------------------------------------------------------
void Texture::RenderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

