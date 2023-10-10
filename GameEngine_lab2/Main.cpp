#include <iostream>
#include "Engine.h"
#include "RenderSystem.h"
#include "InputManager.h"
#include "AssetManager.h"
int main()
{
    Engine* engine = new Engine();
	engine->Initialize();
	engine->Destroy();
	delete engine;
	return 0;
}

