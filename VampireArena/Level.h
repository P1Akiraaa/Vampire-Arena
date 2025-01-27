#pragma once
#include "CoreMinimal.h"
#include "Actor.h"
#include "ShapeObject.h"

class Level
{
	string title;

public:
	template <typename T = Actor>
	static T* SpawnActor()
	{
		const SubclassOf<T>& _ref = SubclassOf(T());
		return SpawnActor(_ref);
	}

	template <typename T = Actor>
	static T* SpawnActor(const SubclassOf<T>& _ref)
	{
		T* _actor = new T(_ref.GetObject());
		_actor->Construct();
		return _actor;
	}

	template <typename T = Actor>
	static T* SpawnActor(const T& _ref)
	{
		T* _actor = new T(_ref);
		_actor->Construct();
		return _actor;
	}
};