#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture){
    SDL_Surface* tmpSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

    return tex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect des){
    SDL_RenderCopy(Game::renderer, tex, &src, &des);
}