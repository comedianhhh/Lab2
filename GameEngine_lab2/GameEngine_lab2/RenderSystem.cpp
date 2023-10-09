#include "RenderSystem.h"
#include <iostream>
#include <SDL.h>
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

	SDL_Window* window = SDL_CreateWindow("Render Window",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width,
		height,
		fullScreen ? SDL_WINDOW_FULLSCREEN : 0);

	if (window == nullptr) {
		std::cout << "Failed to create SDL window: " << SDL_GetError() << std::endl;
		// Handle error
		return;
	}
	SDL_DestroyWindow(window);

	SDL_Quit();

	std::cout << "RenderSystem Initialized" << std::endl;
}
void RenderSystem::Destroy()
{

	std::cout << "RenderSystem Destroyed" << std::endl;
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
	if (rSystem.hasKey("Width"))
	{
		width = rSystem["Width"].ToInt();
		std::cout << "Width: " << width << std::endl;
	}
	if (rSystem.hasKey("Height"))
	{
		height = rSystem["Height"].ToInt();
		std::cout << "Height: " << height << std::endl;
	}
	if (rSystem.hasKey("Fullscreen"))
	{
		fullScreen = rSystem["Fullscreen"].ToBool();
		std::cout << "Fullscreen: " << fullScreen << std::endl;
	}
	std::cout << "RenderSystem Loaded" << std::endl;
}
