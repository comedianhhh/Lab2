#include "Engine.h"
#include <iostream>
#include <string>
#include <list>
#include "Entity.h"
#include "Component.h"

#include "InputManager.h"
	
#include "RenderSystem.h"
#include "AssetManager.h"
#include "SceneManager.h"
#include "Scene.h"

Engine::Engine()
{
	renderSystem = nullptr;
	inputManager = nullptr;
	assetManager = nullptr;
	sceneManager = nullptr;
	std::cout<<	"Engine Created"<<std::endl;
}

Engine::~Engine()
{
	Destroy();
	std::cout << "Engine Destroyed" << std::endl;
}
void Engine::Initialize() 
{
	std::cout << "Engine Initialized" << std::endl;
}
void Engine::Destroy()
{
	renderSystem->Destroy();
	inputManager->Destroy();
	assetManager->Destroy();
	sceneManager->Destroy();

	std::cout << "Engine Destroyed" << std::endl;
}
void Engine::GameLoop()
{
	while (true) {
		inputManager->Update();
		sceneManager->Update();
		renderSystem->Update();
		assetManager->Update();
	}
}
void Engine::Load()
{
	renderSystem = new RenderSystem();
	inputManager = new InputManager();
	assetManager = new AssetManager();
	sceneManager = new SceneManager();

	renderSystem->Initialize();
	inputManager->Initialize();
	assetManager->Initialize();
	sceneManager->Initialize();
}
