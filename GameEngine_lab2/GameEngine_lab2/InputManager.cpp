#include "InputManager.h"
#include<iostream>

InputManager::InputManager()
{
	std::cout << "InputManager Created" << std::endl;
}
InputManager::~InputManager()
{
	Destroy();
	std::cout << "InputManager Destructed" << std::endl;
}
void InputManager::Initialize()
{

	std::cout << "InputManager Initialized" << std::endl;
}
void InputManager::Destroy()
{
	std::cout << "InputManager Destroyed" << std::endl;
}
void InputManager::Update()
{
	std::cout << "InputManager Updated" << std::endl;
}
void InputManager::Load()
{
	std::cout << "InputManager Loaded" << std::endl;
}

