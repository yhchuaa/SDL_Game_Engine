#include "GameObj.h"
#include "TextureManager.h"

GameObj::GameObj(const char* textureSheet, int x, int y){
    objTexture = TextureManager::LoadTexture(textureSheet);
    xpos = x;
    ypos = y;
}

void GameObj::Update(){
    xpos = 0;
    ypos = 0;

    srcRect.h = 48;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    desRect.h = srcRect.h;
    desRect.w = srcRect.w;
    desRect.x = xpos;
    desRect.y = ypos;
}

void GameObj::Render(){
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &desRect);
}