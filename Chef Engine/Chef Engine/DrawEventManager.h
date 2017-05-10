#pragma once
#include <map>
#include <SFML/Graphics.hpp>

namespace ce
{
	class Sprite;

	class DrawEventManager
	{
	public:
		DrawEventManager();

		static void AddSprite(Sprite* sprite);
		static void RemoveSprite(Sprite* sprite);
		static void AddTmxLayers(std::vector<sf::VertexArray>* tileMapLayers);
		void Draw(sf::RenderWindow& window);

	private:
		typedef std::map<int, Sprite*> SpriteMap;
		typedef std::map<int, SpriteMap> OrderSpriteMap;

		// OrderSpriteMap with Sprite components recently created
		static OrderSpriteMap enumToMapNewSpr;

		// Map with Sprite componenets
		static OrderSpriteMap enumToMapSpr;

		// Vector containing layers from Tiled to be drawn
		static std::vector<MapTexture>* m_tileMapLayers;

		static std::vector<sf::RenderStates> renderStates;
	};
}