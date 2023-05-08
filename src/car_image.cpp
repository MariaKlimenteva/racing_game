#include "car_image.h"
#include "game.h"
#include "car.h"
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

	car_t car;
	coordinates_t coordinates = car.get_coordinates();

	SDL_RenderCopyEx(ren, tex, NULL, &dst, 0, NULL, SDL_FLIP_VERTICAL);
	// if(coordinates.get_direction() == 0)
	// {
	// 	SDL_RenderCopyEx(ren, tex, NULL, &dst, 0, NULL, SDL_FLIP_NONE);
	// 	if(coordinates.get_direction() > 0)
	// 	{
	// 		SDL_RenderCopyEx(ren, tex, NULL, &dst, -20, NULL, SDL_FLIP_VERTICAL);
	// 	}
	// 	else SDL_RenderCopyEx(ren, tex, NULL, &dst, 20, NULL, SDL_FLIP_VERTICAL);
	// }

	// if((coordinates.get_direction() == M_PI) || (coordinates.get_direction() == -M_PI))
	// {
	// 	SDL_RenderCopyEx(ren, tex, NULL, &dst, 0, NULL, SDL_FLIP_NONE);
	// 	if(coordinates.get_direction() > 0)
	// 	{
	// 		SDL_RenderCopyEx(ren, tex, NULL, &dst, 20, NULL, SDL_FLIP_VERTICAL);
	// 	}
	// 	else SDL_RenderCopyEx(ren, tex, NULL, &dst, -20, NULL, SDL_FLIP_VERTICAL);
	// }
//положительное == по часовой
//вверх это 0
// вниз это пи или -пи или 2пи

}

