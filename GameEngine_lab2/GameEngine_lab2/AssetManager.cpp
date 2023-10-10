#include "AssetManager.h"
#include <iostream>
AssetManager::AssetManager()
{
	std::cout << "AssetManager Created" << std::endl;
}
AssetManager::~AssetManager()
{
	Destroy();
	std::cout << "AssetManager Destructed" << std::endl;
}
void AssetManager::Initialize()
{
	std::cout << "AssetManager Initialized" << std::endl;
}
void AssetManager::Destroy()
{
	std::cout << "AssetManager Destroyed" << std::endl;
}
void AssetManager::Update()
{
	std::cout << "AssetManager Updated" << std::endl;
}
void AssetManager::Load()
{
	std::cout << "AssetManager Loaded" << std::endl;
}