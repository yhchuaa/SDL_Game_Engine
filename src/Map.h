#pragma once
#include "Game.h"

class Map{
public:
    Map();
    ~Map();

    void LoadMap(uint8_t map[20][25]);
    void DrawMap();
    
private:

    SDL_Rect src, des;

    SDL_Texture* ground;

    int map[20][25];

};