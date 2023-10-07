#pragma once
#ifndef _SCENE_H_
#define _SCENE_H_
#include <list>
#include "Entity.h"
class Scene
{
private:
	std::list<Entity*> entities;
public:
	Scene();
	~Scene();
	void Initialize();
	void Destroy();
	void Update();
	void AddEntity(Entity* entity);
	void RemoveEntity(Entity* entity);
	void Load();
};

#endif // !_SCENE_H_


