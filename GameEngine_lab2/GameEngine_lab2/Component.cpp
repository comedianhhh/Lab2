#include "Component.h"
#include <iostream>
#include "json.hpp"
Component::Component()
{
	std::cout << "Component Created" << std::endl;
}
Component::~Component()
{
	Destory();
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
void Component::Load(json::JSON& eData)
{
	if (eData.hasKey("className"))
	{
		std::string name = eData["className"].ToString();
		if (eData.hasKey("id"))
		{
			int id = eData["id"].ToInt();
			std::cout << "Component ClassNamd and ID: " <<name<<" "<< id << std::endl;
		}
	}

	std::cout << "Component Loaded" << std::endl;
}
