#include "SnakeTile.h"
#include "Game.h"

namespace Snake
{
	void InitSnakeTile(Game& game)
	{
		SnakeTile snakeTile;
		int startPositionX = MAP_TILE_NUM_WIDTH / 2;
		int startPositionY = MAP_TILE_NUM_HEIGHT / 2;

		snakeTile.typeTileSnake = TypeTileSnake::SnakeHeadDirectionRight;
		snakeTile.position2D = game.mapTiles[startPositionX][startPositionY].position2D;
		snakeTile.sprite.setTexture(game.snakeHeadTexture);
		snakeTile.sprite.setRotation(180.f);
		SetSpriteSize(snakeTile.sprite, SNAKE_SIZE, SNAKE_SIZE);
		SetSpriteRelativeOrigin(snakeTile.sprite, 0.5f, 0.5f);
		game.snakeAll.push_back(snakeTile);

		--startPositionX;
		snakeTile.typeTileSnake = TypeTileSnake::SnakeBodyDirectionLeftRight;
		snakeTile.position2D = game.mapTiles[startPositionX][startPositionY].position2D;
		snakeTile.sprite.setTexture(game.snakeBodyTexture);
		game.snakeAll.push_back(snakeTile);

		--startPositionX;
		snakeTile.typeTileSnake = TypeTileSnake::SnakeBodyDirectionLeftRight;
		snakeTile.position2D = game.mapTiles[startPositionX][startPositionY].position2D;
		snakeTile.sprite.setTexture(game.snakeBodyTexture);
		game.snakeAll.push_back(snakeTile);

		--startPositionX;
		snakeTile.typeTileSnake = TypeTileSnake::SnakeTailDirectionLeftRight;
		snakeTile.position2D = game.mapTiles[startPositionX][startPositionY].position2D;
		snakeTile.sprite.setTexture(game.snakeTailTexture);
		snakeTile.sprite.setRotation(270.f);
		game.snakeAll.push_back(snakeTile);
	}

	void CheckWhichTileShouldBetween(Game& game)
	{
		if ((game.snakeAll[0].position2D.y == game.snakeAll[1].position2D.y) && (game.snakeAll[0].position2D.x < game.snakeAll[1].position2D.x) &&
			(game.snakeAll[0].position2D.y == game.snakeAll[2].position2D.y) && (game.snakeAll[0].position2D.x < game.snakeAll[2].position2D.x)
			||
			(game.snakeAll[0].position2D.y == game.snakeAll[1].position2D.y) && (game.snakeAll[0].position2D.x > game.snakeAll[1].position2D.x) &&
			(game.snakeAll[0].position2D.y == game.snakeAll[2].position2D.y) && (game.snakeAll[0].position2D.x > game.snakeAll[2].position2D.x))
		{
			game.snakeAll[1].typeTileSnake = TypeTileSnake::SnakeBodyDirectionLeftRight;
			game.snakeAll[1].sprite.setTexture(game.snakeBodyTexture);
		}
		else if ((game.snakeAll[0].position2D.y < game.snakeAll[1].position2D.y) && (game.snakeAll[0].position2D.x == game.snakeAll[1].position2D.x) &&
				(game.snakeAll[0].position2D.y < game.snakeAll[2].position2D.y) && (game.snakeAll[0].position2D.x == game.snakeAll[2].position2D.x)
				||
				(game.snakeAll[0].position2D.y > game.snakeAll[1].position2D.y) && (game.snakeAll[0].position2D.x == game.snakeAll[1].position2D.x) &&
				(game.snakeAll[0].position2D.y > game.snakeAll[2].position2D.y) && (game.snakeAll[0].position2D.x == game.snakeAll[2].position2D.x))
		{
			game.snakeAll[1].typeTileSnake = TypeTileSnake::SnakeBodyDirectionUpDown;
			game.snakeAll[1].sprite.setTexture(game.snakeBodyTexture);
			game.snakeAll[1].sprite.setRotation(90.f);
		}
		else if ((game.snakeAll[0].position2D.y > game.snakeAll[1].position2D.y) && (game.snakeAll[0].position2D.x == game.snakeAll[1].position2D.x) &&
				(game.snakeAll[0].position2D.y > game.snakeAll[2].position2D.y) && (game.snakeAll[0].position2D.x > game.snakeAll[2].position2D.x)
				||
				(game.snakeAll[0].position2D.y == game.snakeAll[1].position2D.y) && (game.snakeAll[0].position2D.x < game.snakeAll[1].position2D.x) &&
				(game.snakeAll[0].position2D.y < game.snakeAll[2].position2D.y) && (game.snakeAll[0].position2D.x < game.snakeAll[2].position2D.x))
		{
			game.snakeAll[1].typeTileSnake = TypeTileSnake::SnakeTurnBodyLeftDown;
			game.snakeAll[1].sprite.setTexture(game.snakeTurnBodyTexture);
			game.snakeAll[1].sprite.setRotation(90.f);
		}
		else if ((game.snakeAll[0].position2D.y == game.snakeAll[1].position2D.y) && (game.snakeAll[0].position2D.x > game.snakeAll[1].position2D.x) &&
				(game.snakeAll[0].position2D.y < game.snakeAll[2].position2D.y) && (game.snakeAll[0].position2D.x > game.snakeAll[2].position2D.x)
				||
				(game.snakeAll[0].position2D.y > game.snakeAll[1].position2D.y) && (game.snakeAll[0].position2D.x == game.snakeAll[1].position2D.x) &&
				(game.snakeAll[0].position2D.y > game.snakeAll[2].position2D.y) && (game.snakeAll[0].position2D.x < game.snakeAll[2].position2D.x))
		{
			game.snakeAll[1].typeTileSnake = TypeTileSnake::SnakeTurnBodyLeftDown;
			game.snakeAll[1].sprite.setTexture(game.snakeTurnBodyTexture);
			game.snakeAll[1].sprite.setRotation(0.f);
		}
		else if ((game.snakeAll[0].position2D.y == game.snakeAll[1].position2D.y) && (game.snakeAll[0].position2D.x > game.snakeAll[1].position2D.x) &&
				(game.snakeAll[0].position2D.y > game.snakeAll[2].position2D.y) && (game.snakeAll[0].position2D.x > game.snakeAll[2].position2D.x)
				||
				(game.snakeAll[0].position2D.y < game.snakeAll[1].position2D.y) && (game.snakeAll[0].position2D.x == game.snakeAll[1].position2D.x) &&
				(game.snakeAll[0].position2D.y < game.snakeAll[2].position2D.y) && (game.snakeAll[0].position2D.x < game.snakeAll[2].position2D.x))
		{
			game.snakeAll[1].typeTileSnake = TypeTileSnake::SnakeTurnBodyLeftDown;
			game.snakeAll[1].sprite.setTexture(game.snakeTurnBodyTexture);
			game.snakeAll[1].sprite.setRotation(270.f);
		}
		else if ((game.snakeAll[0].position2D.y < game.snakeAll[1].position2D.y) && (game.snakeAll[0].position2D.x == game.snakeAll[1].position2D.x) &&
				(game.snakeAll[0].position2D.y < game.snakeAll[2].position2D.y) && (game.snakeAll[0].position2D.x > game.snakeAll[2].position2D.x)
				||
				(game.snakeAll[0].position2D.y == game.snakeAll[1].position2D.y) && (game.snakeAll[0].position2D.x < game.snakeAll[1].position2D.x) &&
				(game.snakeAll[0].position2D.y > game.snakeAll[2].position2D.y) && (game.snakeAll[0].position2D.x < game.snakeAll[2].position2D.x))
		{
				game.snakeAll[1].typeTileSnake = TypeTileSnake::SnakeTurnBodyLeftDown;
				game.snakeAll[1].sprite.setTexture(game.snakeTurnBodyTexture);
				game.snakeAll[1].sprite.setRotation(180.f);
		}
	}

	void CheckTailDirection(Game& game)
	{
		const int SECOND_FINITE_ELEMENT = game.snakeAll.size() - 2;
		// ¬право
		if (game.snakeAll[SECOND_FINITE_ELEMENT].position2D.x > game.snakeAll.back().position2D.x)
		{
			game.snakeAll[SECOND_FINITE_ELEMENT].typeTileSnake = TypeTileSnake::SnakeTailDirectionLeftRight;
			game.snakeAll[SECOND_FINITE_ELEMENT].sprite.setTexture(game.snakeTailTexture);
			game.snakeAll[SECOND_FINITE_ELEMENT].sprite.setRotation(270.f);
		}
		// ¬лево
		else if (game.snakeAll[SECOND_FINITE_ELEMENT].position2D.x < game.snakeAll.back().position2D.x)
		{
			game.snakeAll[SECOND_FINITE_ELEMENT].typeTileSnake = TypeTileSnake::SnakeTailDirectionLeftRight;
			game.snakeAll[SECOND_FINITE_ELEMENT].sprite.setTexture(game.snakeTailTexture);
			game.snakeAll[SECOND_FINITE_ELEMENT].sprite.setRotation(90.f);
		}
		// ¬низ
		else if (game.snakeAll[SECOND_FINITE_ELEMENT].position2D.y > game.snakeAll.back().position2D.y)
		{
			game.snakeAll[SECOND_FINITE_ELEMENT].typeTileSnake = TypeTileSnake::SnakeTailDirectionUpDown;
			game.snakeAll[SECOND_FINITE_ELEMENT].sprite.setTexture(game.snakeTailTexture);
			game.snakeAll[SECOND_FINITE_ELEMENT].sprite.setRotation(0.f);
		}
		// ¬верх
		else if (game.snakeAll[SECOND_FINITE_ELEMENT].position2D.y < game.snakeAll.back().position2D.y)
		{
			game.snakeAll[SECOND_FINITE_ELEMENT].typeTileSnake = TypeTileSnake::SnakeTailDirectionUpDown;
			game.snakeAll[SECOND_FINITE_ELEMENT].sprite.setTexture(game.snakeTailTexture);
			game.snakeAll[SECOND_FINITE_ELEMENT].sprite.setRotation(180.f);
		}
	}

	void UpdateSnakeTiles(Game& game)
	{
		game.snakeAll.emplace(++game.snakeAll.cbegin(), game.snakeAll[0]);

		switch (game.snakeAll[0].typeTileSnake)
		{
			case TypeTileSnake::SnakeHeadDirectionLeft:
			{
				game.snakeAll[0].position2D.x -= SNAKE_SIZE;
				CheckWhichTileShouldBetween(game);
				break;
			}
			case TypeTileSnake::SnakeHeadDirectionUp:
			{
				game.snakeAll[0].position2D.y -= SNAKE_SIZE;
				CheckWhichTileShouldBetween(game);
				break;
			}
			case TypeTileSnake::SnakeHeadDirectionRight:
			{
				game.snakeAll[0].position2D.x += SNAKE_SIZE;
				CheckWhichTileShouldBetween(game);
				break;
			}
			case TypeTileSnake::SnakeHeadDirectionDown:
			{
				game.snakeAll[0].position2D.y += SNAKE_SIZE;
				CheckWhichTileShouldBetween(game);
				break;
			}
		}
		CheckTailDirection(game);
		game.snakeAll.pop_back();
	}

	void DrawSnakeTile(SnakeTile& snakeTile, sf::RenderWindow& window)
	{
		snakeTile.sprite.setPosition(snakeTile.position2D.x, snakeTile.position2D.y);
		window.draw(snakeTile.sprite);
	}
}
