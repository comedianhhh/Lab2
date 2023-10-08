#include "SceneManager.h"
#include <iostream>
#include "json.hpp"

SceneManager::SceneManager()
{
	std::cout << "SceneManager created" << std::endl;
}
SceneManager::~SceneManager()
{
	Destroy();
	std::cout << "SceneManager destroyed" << std::endl;
}
void SceneManager::Initialize()
{
	std::cout << "SceneManager initialized" << std::endl;
}
void SceneManager::Destroy()
{
	for (Scene* scene : scenes) {
		delete scene;
	}
	scenes.clear();
	std::cout << "SceneManager destroyed" << std::endl;
}
void SceneManager::Update()
{
	for (Scene* scene : scenes) {
		scene->Update();
	}
}
void SceneManager::AddScene(Scene* scene)
{
	scenes.push_back(scene);
}
void SceneManager::RemoveScene(Scene* scene)
{
	scenes.remove(scene);
}
void SceneManager::Load(json::JSON& sSystem)
{

	Scene* newScene = new Scene();
	newScene->Load(sSystem);
	AddScene(newScene);
	

}