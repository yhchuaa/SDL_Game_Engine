#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2D.h"

Map* map;
SDL_Renderer* Game::renderer = nullptr;
Manager manager;
SDL_Event Game::event;
auto& player(manager.addEntity());

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen){
	int flags = 0;
	
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}
	map = new Map();

	player.addComponents<TransformComponent>();
	player.addComponents<SpriteComponent>("../assets/player/idle.png");
	player.addComponents<KeyboardController>();
}

void Game::handleEvents(){

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT :
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update(){
	manager.refresh();
	manager.update();
}

void Game::render(){
	SDL_RenderClear(renderer);
	map->DrawMap();
	// std::cout << "(" << player.getComponent<TransformComponent>().position.x << "," << player.getComponent<TransformComponent>().position.y << ")" << std::endl;
	manager.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}