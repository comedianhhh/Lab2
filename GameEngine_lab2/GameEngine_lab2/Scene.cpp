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
	std::cout << "Scene Destructed" << std::endl;
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
	std::cout << "Scene Updated" << std::endl;
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
	if (sData.hasKey("Entities"))
	{
		json::JSON entities = sData["Entities"];

		for (auto& entity : entities.ArrayRange())
		{
			if (entity.hasKey("Name"))
			{
				std::string name = entity["Name"].ToString();
				std::cout << "Entity Name: " << name << std::endl;

				Entity* newEntity = new Entity();
				newEntity->Load(entity); 

				AddEntity(newEntity);
			}
		}
	}
	std::cout<< "Scene Loaded" << std::endl;

}