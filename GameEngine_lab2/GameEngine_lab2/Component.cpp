#include "Component.h"
#include <iostream>
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
