#include "Game.h"

class GameObj {
public:
    GameObj(const char* textureSheet, int x, int y);
    ~GameObj();

    void Update();
    void Render();

private:

    int xpos;
    int ypos;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, desRect;
    SDL_Renderer* renderer;
};