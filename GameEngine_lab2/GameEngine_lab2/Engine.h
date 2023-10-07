#pragma once
#ifndef _ENGINE_H_
#define _ENGINE_H_
#include "RenderSystem.h"
#include "InputManager.h"
#include "AssetManager.h"
#include "SceneManager.h"
class Engine
{
private:
	RenderSystem* renderSystem;
	InputManager* inputManager;
	AssetManager* assetManager;
	SceneManager* sceneManager;
public:
	Engine();
	~Engine();

	void Initialize();
	void Destroy();

	void GameLoop();
	void Load();

};
#endif // !_ENGINE_H_

