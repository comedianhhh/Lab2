#pragma once
#ifndef _COMPONENT_H_
#define _COMPONENT_H_
#include "json.hpp"
class Component
{
private:
		int id=0;
public:
		Component();
		~Component();

		void initialize();
		void Destory();

		int GetComponentId();
		void Update();
		void Load(json::JSON& cData);
};
#endif // !_COMPONENT_H_


