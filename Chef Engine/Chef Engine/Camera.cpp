#include "Camera.h"
#include "GameObject.h"
#include "MapHandler.h"
#include "Math.h"

using ce::Camera;

Camera::Camera()
{
	follow = false;
}


Camera::~Camera()
{
}


void ce::Camera::SetSize(const sf::Vector2f &size)
{
	this->size = size;
	view.setSize(size);
}


sf::Vector2f ce::Camera::GetSize() const
{
	return size;
}

void ce::Camera::SetZoom(float zoom)
{
	view.zoom(zoom);
	this->zoom *= zoom;
}

float ce::Camera::GetZoom() const
{
	return 0.0f;
}


sf::View ce::Camera::GetView() const
{
	return view;
}



void ce::Camera::SetCenter(const sf::Vector2f &center)
{
	this->center = center;
	view.setCenter(center);
}


sf::Vector2f ce::Camera::GetCenter() const
{
	return this->center;
}


bool ce::Camera::GetFollow() const
{
	return follow;
}

void ce::Camera::SetFollow(const bool & follow)
{
	this->follow = follow;
}


void ce::Camera::Update()
{
	mapSize = ce::MapHandler::GetMapSize();

	if (follow)
	{
		view.setCenter(gameObject->GetTransform()->GetPosition());
	}

	sf::Vector2f clampedCenter = sf::Vector2f(ce::Math::ClampF(view.getCenter().x, mapSize.x - (size.x / 2) * zoom, 0 + (size.x / 2) * zoom),
		ce::Math::ClampF(view.getCenter().y, mapSize.y - (size.y / 2) * zoom, 0 + (size.y / 2) * zoom));

	view.setCenter(clampedCenter);
}

void ce::Camera::DoBind(lua_State * L)
{
	luabridge::getGlobalNamespace(L)
		.beginNamespace("Chef")
			.deriveClass<Camera, Component>("Camera")
				.addProperty("size", &Camera::GetSize, &Camera::SetSize)
				.addProperty("center", &Camera::GetCenter, &Camera::SetCenter)
				.addProperty("follow", &Camera::GetFollow, &Camera::SetFollow)
				.addProperty("zoom", &Camera::GetZoom, &Camera::SetZoom)
				.addProperty("view", &Camera::GetView)
			.endClass()
		.endNamespace();
}


