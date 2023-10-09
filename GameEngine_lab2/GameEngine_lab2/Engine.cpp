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
	renderSystem->Initialize();
	inputManager->Initialize();
	assetManager->Initialize();
	sceneManager->Initialize();

	std::ifstream inputStream("GameSettings.json");
	Load(inputStream);
	std::ifstream levelStream("GameLevelExample.json");
	Load(levelStream);
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
		json::JSON sManager = document["SceneManager"];
		sceneManager->Load(sManager);
	}
}
