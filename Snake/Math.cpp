#include "Math.h"
#include "Game.h"

namespace Snake
{
	Position2D GetMapTilePositionInScreen(float positionWidth, float positionHeight)
	{
		Position2D result;
		result.x = BORDER_LEFT_RIGHT + TILE_SIZE * positionWidth;
		result.y = BORDER_UP_DOWN + TILE_SIZE * positionHeight;
		return result;
	}
	
	Position2D GetRandomPositionInScreen(const Game& game, int startX, int endX, int startY, int endY)
	{
		Position2D result = game.mapTiles[rand() % (endX - startX + 1) + startX][rand() % (endY - startY + 1) + startY].position2D;
		return result;
	}

	void SetSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight)
	{
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sf::Vector2f scale = { desiredWidth / spriteRect.width, desiredHeight / spriteRect.height };
		sprite.setScale(scale);
	}

	void SetSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY)
	{
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sprite.setOrigin(originX * spriteRect.width, originY * spriteRect.height);
	}

	sf::Vector2f GetTextOrigin(const sf::Text& text, const Vector2D& relativePosition)
	{
		sf::FloatRect textSize = text.getLocalBounds();

		return {
			(textSize.left + textSize.width) * relativePosition.x,
			(textSize.top + textSize.height) * relativePosition.y,
		};
	}
}