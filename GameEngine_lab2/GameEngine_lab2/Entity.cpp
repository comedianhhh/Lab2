#include "Entity.h"
#include "Component.h"
#include <iostream>
#include "json.hpp"
Entity::Entity() {
	name = "Default Entity";
	std::cout << "Entity created" << std::endl;
}

Entity::~Entity() {
	Destroy();
	std::cout << "Entity Destructed" << std::endl;
}

void Entity::Initialize() {
	std::cout << "Entity initialized" << std::endl;
}

void Entity::Destroy() {
	for (Component* comp : components) {
		delete comp;
	}
	components.clear();
	std::cout<< "Entity destroyed" << std::endl;
}

void Entity::AddComponent(Component* component) {
	components.push_back(component);
	std::cout<< "Entity added component" << std::endl;
}

void Entity::RemoveComponent(Component* component) {
	components.remove(component);
}

void Entity::Update() {
	for (Component* comp : components) {
		comp->Update();
	}
	std::cout << name << "Entity updated" << std::endl;
}

std::string& Entity::GetName() {
	return name;
}

void Entity::Load(json::JSON& eData)
{
	if (eData.hasKey("name")) 
	{
		std::cout << "---------------------------" << std::endl;
		std::string name = eData["name"].ToString();
	}
	// Load components
	if (eData.hasKey("Components"))
	{
		json::JSON components = eData["Components"];

		for (auto& component : components.ArrayRange())
		{
			if (component.hasKey("className") && component.hasKey("id"))
			{
				Component* newComponent = new Component();
				newComponent->Load(component);
				AddComponent(newComponent);
			}
		}
	}
}