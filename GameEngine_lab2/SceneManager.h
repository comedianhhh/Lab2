#pragma once
#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_
#include <list>
#include "Scene.h"
class SceneManager
{
private:
	std::list<Scene*> scenes;

public:
	SceneManager();
	~SceneManager();
	void Initialize();
	void Destroy();
	void Update();

	void AddScene(Scene* scene);
	void RemoveScene(Scene* scene);

	void Load(json::JSON& SceneSystem);
};

#endif // !_SCENEMANAGER_H_


