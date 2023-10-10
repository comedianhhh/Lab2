#include "Engine.h"
#include <iostream>
#include <string>
#include <list>
#include "Entity.h"
#include "Component.h"

#include "InputManager.h"
#include <fstream>
#include "RenderSystem.h"
#include "AssetManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "json.hpp"

Engine::Engine():renderSystem(new RenderSystem()),inputManager(new InputManager()),assetManager(new AssetManager()),sceneManager(new SceneManager())
{
	std::cout<<	"Engine Created"<<std::endl;
}

Engine::~Engine()
{
	std::cout << "Engine Destructed" << std::endl;
}
void Engine::Initialize() 
{
	std::ifstream inputStream("GameSettings.json");
	Load(inputStream);
	std::ifstream levelStream("GameLevelExample.json");
	Load(levelStream);

	renderSystem->Initialize();
	inputManager->Initialize();
	assetManager->Initialize();
	sceneManager->Initialize();

	GameLoop();
	std::cout << "Engine Initialized" << std::endl;
}
void Engine::Destroy()
{

	delete renderSystem;
	delete inputManager;
	delete assetManager;
	delete sceneManager;
	std::cout << "Engine Destroyed" << std::endl;
}
void Engine::GameLoop()
{
	int i = 0;
	while (i<5) {
		inputManager->Update();
		sceneManager->Update();
		renderSystem->Update();
		assetManager->Update();
		i++;
		std::cout<<"GameLoop"<<std::endl;
	}
}
void Engine::Load(std::ifstream& inputStream)
{

	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON document = json::JSON::Load(str);

	if (document.hasKey("Engine"))
	{
		json::JSON engine = document["Engine"];
		if (engine.hasKey("DefaultFile"))
		{
			std::string defaultFile = engine["DefaultFile"].ToString();
			std::cout << "DefaultFile: " << defaultFile << std::endl;
		}
	}
	if (document.hasKey("RenderSystem"))
	{
		json::JSON rSystem = document["RenderSystem"];
		renderSystem->Load(rSystem);
	}
	if (document.hasKey("SceneManager"))
	{
		sceneManager->Load(document);
	}
}
