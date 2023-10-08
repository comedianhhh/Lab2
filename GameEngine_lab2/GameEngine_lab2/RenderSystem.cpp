#include "RenderSystem.h"
#include <iostream>
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
	std::cout << "RenderSystem Initialized" << std::endl;
}
void RenderSystem::Destroy()
{
	delete this;
	std::cout << "RenderSystem Destroyed" << std::endl;
}
void RenderSystem::Update()
{
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
