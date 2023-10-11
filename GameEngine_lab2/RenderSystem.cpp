#include "RenderSystem.h"
#include <iostream>
#include <SDL.h>
#include"SDL_image.h"

RenderSystem::RenderSystem()
{
	std::cout << "RenderSystem Created" << std::endl;
}
RenderSystem::~RenderSystem()
{
	Destroy();
	std::cout << "RenderSystem Destroyed" << std::endl;
}
void RenderSystem::Initialize()
{
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
		// Handle initialization error
		return;
	}

	// Initialize SDL_image
	int imgFlags = IMG_INIT_PNG;
	if ((IMG_Init(imgFlags) & imgFlags) != imgFlags) {
		std::cout << "Failed to initialize SDL_image: " << IMG_GetError() << std::endl;
		// Handle initialization error
		return;
	}

	// Create SDL window
	window = SDL_CreateWindow("SDL Example",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, 
		width,
		height,
		0);
	if (!window) {
		std::cout << "Failed to create SDL window: " << SDL_GetError() << std::endl;
		// Handle window creation error
		return;
	}

	// Create SDL renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		std::cout << "Failed to create SDL renderer: " << SDL_GetError() << std::endl;
		return;
	}

	std::cout << "RenderSystem Initialized"<< std::endl;
}
void RenderSystem::Destroy()
{

	std::cout << "RenderSystem Destructed" << std::endl;
}
void RenderSystem::Update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		// Process events using SDL_PollEvents
	}
	std::cout << "RenderSystem Updated" << std::endl;
}
void RenderSystem::Load(json::JSON& rSystem)
{
	if (rSystem.hasKey("Name"))
	{
		name = rSystem["Name"].ToString();
		std::cout << "Name: " << name << std::endl;
	}
	if (rSystem.hasKey("width"))
	{
		width = rSystem["width"].ToInt();
		std::cout << "width: " << width << std::endl;
	}
	if (rSystem.hasKey("height"))
	{
		height = rSystem["height"].ToInt();
		std::cout << "height: " << height << std::endl;
	}
	if (rSystem.hasKey("fullscreen"))
	{
		fullScreen = rSystem["fullscreen"].ToBool();
		std::cout << "fullscreen: " << fullScreen << std::endl;
	}
	std::cout << "**************RenderSystem Loaded************" << std::endl;
}
