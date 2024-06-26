#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "Constants.h"

namespace Snake
{
	enum MapTileEnum
	{
		TypeTileGround_1 = 1,
		TypeTileGround_2,
		TypeTileWall
	};

	struct MapTile
	{
		Position2D position2D;
		sf::RectangleShape rectangleShape;
		sf::Sprite sprite;
		MapTileEnum mapTileEnum = MapTileEnum::TypeTileGround_1;
	};

	struct Game;

	void InitMapTiles(Game& game);
	void DrawMapTile(MapTile& mapTile, sf::RenderWindow& window);
}
