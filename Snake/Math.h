#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"

namespace Snake
{
	struct Vector2D
	{
		float x = 0.0f;
		float y = 0.0f;
	};

	typedef Vector2D Position2D;

	struct Game;

	Position2D GetMapTilePositionInScreen(float positionWidth, float positionHeight);
	Position2D GetRandomPositionInScreen(const Game& game, int startX, int endX, int startY, int endY);
	void SetSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight);
	void SetSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY);
	sf::Vector2f GetTextOrigin(const sf::Text& text, const Vector2D& relativePosition);
}
