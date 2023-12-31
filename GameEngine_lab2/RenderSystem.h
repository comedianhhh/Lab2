#pragma once
#ifndef _RENDERSYSTEM_H_
#define _RENDERSYSTEM_H_
#include <string>
#include "json.hpp"
class RenderSystem
{
private:
	std::string name="";
	int width=0;
	int height=0;
	bool fullScreen=false;
public:
	RenderSystem();
	~RenderSystem();
	void Initialize();
	void Destroy();
	void Update();
	void Load(json::JSON& RenderSystem);
};
#endif // !_RENDERSYSTEM_H_


