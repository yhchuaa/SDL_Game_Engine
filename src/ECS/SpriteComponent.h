#pragma once
#include "Components.h"
#include "SDL2/SDL.h"

class SpriteComponent : public Component{
private:
    TransformComponent* transform;
    SDL_Texture *texture;
    SDL_Rect srcRect, desRect;

public:
    SpriteComponent() = default;
    SpriteComponent(const char* path){
        setTex(path);
    }

    void setTex(const char* path){
        texture = TextureManager::LoadTexture(path);
    }

    void init() override{
        transform = &entity->getComponent<TransformComponent>();

        srcRect.h = 48;
        srcRect.w = 32;
        srcRect.x = 0;
        srcRect.y = 0;

        desRect.h = srcRect.h;
        desRect.w = srcRect.w;
    } 

    void update() override{
        desRect.x = (int)transform->position.x;
        desRect.y = (int)transform->position.y;
    }

    void draw() override{
        TextureManager::Draw(texture, srcRect, desRect);
    }
};