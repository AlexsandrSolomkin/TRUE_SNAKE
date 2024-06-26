#include "Apple.h"
#include "Game.h"

namespace Snake
{
	void InitApple(Apple& apple, const Game& game)
	{
		apple.position2D = GetRandomPositionInScreen(game, 1, MAP_TILE_NUM_WIDTH - 2, 1, MAP_TILE_NUM_HEIGHT - 2);

		apple.sprite.setTexture(game.appleTexture);
		SetSpriteSize(apple.sprite, APPLE_SIZE, APPLE_SIZE);
		SetSpriteRelativeOrigin(apple.sprite, 0.5f, 0.5f);
	}

	void DrawApple(Apple& apple, sf::RenderWindow& window)
	{
		apple.sprite.setPosition(apple.position2D.x, apple.position2D.y);
		window.draw(apple.sprite);
	}
}
