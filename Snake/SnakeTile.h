#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "Constants.h"
#include <vector>

namespace Snake
{
	enum TypeTileSnake
	{
		SnakeHeadDirectionLeft = 0,
		SnakeHeadDirectionUp,
		SnakeHeadDirectionRight,
		SnakeHeadDirectionDown,

		SnakeBodyDirectionLeftRight,
		SnakeBodyDirectionUpDown,

		SnakeTurnBodyLeftUp,
		SnakeTurnBodyRightUp,
		SnakeTurnBodyLeftDown,
		SnakeTurnBodyRightDown,

		SnakeTailDirectionLeftRight,
		SnakeTailDirectionUpDown
	};

	struct SnakeTile
	{
		TypeTileSnake typeTileSnake;
		Position2D position2D;
		sf::CircleShape shape;
		sf::Sprite sprite;
	};

	struct Game;

	void InitSnakeTile(Game& game);
	void CheckWhichTileShouldBetween(Game& game);
	void CheckTailDirection(Game& game);
	void UpdateSnakeTiles(Game& game);
	void DrawSnakeTile(SnakeTile& snakeTile, sf::RenderWindow& window);
}
