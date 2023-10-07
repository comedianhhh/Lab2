#include "Entity.h"

Entity::Entity() {
	name = "Default Entity";
	std::cout << "Entity created" << std::endl;
}

Entity::~Entity() {
	Destroy();
	std::cout << "Entity destroyed" << std::endl;
}

void Entity::Initialize() {
	std::cout << name << " initialized" << std::endl;
}

void Entity::Destroy() {
	for (Component* comp : components) {
		comp->Destory();
	}
	components.clear();
	std::cout << name << " destroyed" << std::endl;
}

void Entity::AddComponent(Component* component) {
	components.push_back(component);
}

void Entity::RemoveComponent(Component* component) {
	components.remove(component);
}

void Entity::Update() {
	for (Component* comp : components) {
		comp->Update();
	}
}

std::string& Entity::GetName() {
	return name;
}

void Entity::Load() {
	// Load entity data
}