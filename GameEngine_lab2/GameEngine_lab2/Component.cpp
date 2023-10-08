#include "Component.h"
#include <iostream>
#include "json.hpp"
Component::Component()
{
	std::cout << "Component Created" << std::endl;
}
Component::~Component()
{
	std::cout << "Component Destroyed" << std::endl;
}
void Component::initialize()
{
	std::cout << "Component Initialized" << std::endl;
}
void Component::Destory()
{
	delete this;
	std::cout << "Component Destroyed" << std::endl;
}
int Component::GetComponentId()
{
	return id;
}
void Component::Update()
{
	
	
	std::cout << "Component Updated" << std::endl;

}
void Component::Load(json::JSON& eData)
{
	std::cout << "Component Loaded" << std::endl;
}
