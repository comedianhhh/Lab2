#include "Component.h"
#include <iostream>
#include "json.hpp"
Component::Component()
{
	std::cout << "Component Created" << std::endl;
}
Component::~Component()
{
	std::cout << "Component Destructed" << std::endl;
}
void Component::initialize()
{
	std::cout << "Component Initialized" << std::endl;
}
void Component::Destory()
{
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
	std::string className = eData["className"].ToString();
	int id = eData["id"].ToInt();

	std::cout << "Component - className: " << className << ", id: " << id << std::endl;

	std::cout << "Component Loaded" << std::endl;
	std::cout << "---------------------------" << std::endl;
}
