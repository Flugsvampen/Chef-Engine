#include "GameObject.h"
#include "Component.h"

//using namespace ce;

ce::GameObject::GameObject()
{
	GameObject("none");
}

ce::GameObject::GameObject(std::string name)
{ 
	this->name = name;
	instanceID = uniqueIDCounter++;
	isNew = true;
}

void ce::GameObject::SetActive(bool active)
{
	m_active = active;
}


bool ce::GameObject::operator==(const GameObject & other)
{
	if (instanceID == other.instanceID)
	{
		// This is the same gameobject
		return true;
	}

	return false;
}

void ce::GameObject::ComponentUpdate()
{
}
