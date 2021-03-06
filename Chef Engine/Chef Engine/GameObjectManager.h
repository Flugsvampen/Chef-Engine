////////////////////////////////////////////////////////////
//
// Chef Engine
// Copyright (C) 2017 Oskar Svensson
//  
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
//
// Author: Dennis Karlsson
//
////////////////////////////////////////////////////////////


#pragma once
#include "Common.h"

#include <map>

namespace ce
{
	class GameObject;

	class GameObjectManager
	{
	public:
		CHEF_API GameObjectManager();

		static void Initialize();

		static void AddObject(GameObject* object);

		static void RemoveObject(GameObject* object);

        CHEF_API static void CallUpdate();

	private:
		typedef std::map<uint64, GameObject*> GameObjectMap;
		typedef std::map<uint64, GameObjectMap> LayerObjectMap;

		// Map with GameObjects 
		static LayerObjectMap enumToMapObj;

		// Map with GameObjects recently created
		static LayerObjectMap enumToMapNewObj;
	};
}