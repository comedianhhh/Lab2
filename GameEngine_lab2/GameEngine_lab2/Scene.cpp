#include "Scene.h"
#include <iostream>
#include "json.hpp"

Scene::Scene()
{
	std::cout << "Scene Created" << std::endl;
}
Scene::~Scene()
{
	Destroy();
	std::cout << "Scene Destroyed" << std::endl;
}
void Scene::Initialize()
{
	std::cout << "Scene Initialized" << std::endl;
}
void Scene::Destroy()
{
	for (Entity* entity : entities) {
		delete entity;
	}
	entities.clear();
	std::cout << "Scene Destroyed" << std::endl;
}
void Scene::Update()
{
	for (Entity* entity : entities) {
		entity->Update();
	}
}
void Scene::AddEntity(Entity* entity)
{
	entities.push_back(entity);
}
void Scene::RemoveEntity(Entity* entity)
{
	entities.remove(entity);
}
void Scene::Load(json::JSON& sData)
{
	if (sData.hasKey("name")) 
	{
		std::cout << "scene 1" << "\n";
	}

	json::JSON entities = sData["Entities"];

	for (auto& entity : entities.ArrayRange()) {

		Entity* e = new Entity();

		e->Load(entity);
	}
}