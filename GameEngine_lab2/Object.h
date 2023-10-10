#pragma once
#ifndef _OBJECT_H_
#define _OBJECT_H_
class Object
{
private:
	bool initialized = false;
public:
		Object();
		~Object();
		void Destroy();
		void Initialize();
		bool isInitialized();
		void Load();
};

#endif // !_OBJECT_H_


