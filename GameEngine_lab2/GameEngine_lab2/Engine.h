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
	RenderSystem* renderer;
	InputManager* input;
	AssetManager* assets;
	SceneManager* sceneManager;
public:
	Engine();
	~Engine();

	void Initialize();
	void Destroy();

	//int width;
	//int height;

};
#endif // !_ENGINE_H_

