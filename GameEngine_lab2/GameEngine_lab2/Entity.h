#pragma once
#ifndef _ENTITY_H_
#define _ENTITY_H_
#include "Component.h"
#include <iostream>
#include <list>

class Entity {
private:
	std::list<Component*> components;
	std::string name;
public:
	Entity();
	~Entity();

	void Initialize();
	void Destroy();

	void AddComponent(Component* component);
	void RemoveComponent(Component* component);
	void Update();
	std::string& GetName();
	void Load();

	
};
#endif // !_ENTITY_H_

