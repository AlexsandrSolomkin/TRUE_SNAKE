#include "MapTile.h"
#include "Game.h"

namespace Snake
{
	void InitMapTiles(Game& game)
	{
		for (int i = 0; i < MAP_TILE_NUM_WIDTH; ++i)
		{
			for (int j = 0; j < MAP_TILE_NUM_HEIGHT; ++j)
			{
				game.mapTiles[i][j].position2D = GetMapTilePositionInScreen(i, j);

				if ((i == 0) || (i == MAP_TILE_NUM_WIDTH - 1) ||
					(j == 0) || (j == MAP_TILE_NUM_HEIGHT - 1))
				{
					game.mapTiles[i][j].sprite.setTexture(game.mapWallTexture);
					game.mapTiles[i][j].mapTileEnum = MapTileEnum::TypeTileWall;
					SetSpriteSize(game.mapTiles[i][j].sprite, TILE_SIZE, TILE_SIZE);
					SetSpriteRelativeOrigin(game.mapTiles[i][j].sprite, 0.5f, 0.5f);
				}
				else
				{
					if ((i + j) % 2 == 0)
					{
						game.mapTiles[i][j].sprite.setTexture(game.mapGroundTexture_1);
						game.mapTiles[i][j].mapTileEnum = MapTileEnum::TypeTileGround_1;
						SetSpriteSize(game.mapTiles[i][j].sprite, TILE_SIZE, TILE_SIZE);
						SetSpriteRelativeOrigin(game.mapTiles[i][j].sprite, 0.5f, 0.5f);
					}
					else
					{
						game.mapTiles[i][j].sprite.setTexture(game.mapGroundTexture_2);
						game.mapTiles[i][j].mapTileEnum = MapTileEnum::TypeTileGround_2;
						SetSpriteSize(game.mapTiles[i][j].sprite, TILE_SIZE, TILE_SIZE);
						SetSpriteRelativeOrigin(game.mapTiles[i][j].sprite, 0.5f, 0.5f);
					}
				}
			}
		}
	}

	void DrawMapTile(MapTile& mapTile, sf::RenderWindow& window)
	{
		mapTile.sprite.setPosition(mapTile.position2D.x, mapTile.position2D.y);
		window.draw(mapTile.sprite);
	}
}
