#include "Game.h"
#include <cassert>
#include <vector>

namespace Snake
{
	void RestartGame(Game& game)
	{
		InitUIMenu(game.uiMenu, game.font);
		InitMapTiles(game);
		InitApple(game.apple, game);
		InitSnakeTile(game);
	}

	void InitGame(Game& game)
	{
		assert(game.mapGroundTexture_1.loadFromFile(RESOURCHES_PATH + "\\Ground_1.png"));
		assert(game.mapGroundTexture_2.loadFromFile(RESOURCHES_PATH + "\\Ground_2.png"));
		assert(game.mapWallTexture.loadFromFile(RESOURCHES_PATH + "\\Wall.png"));

		assert(game.appleTexture.loadFromFile(RESOURCHES_PATH + "\\Apple.png"));

		assert(game.snakeHeadTexture.loadFromFile(RESOURCHES_PATH + "\\SnakeHead.png"));
		assert(game.snakeBodyTexture.loadFromFile(RESOURCHES_PATH + "\\SnakeBody.png"));
		assert(game.snakeTurnBodyTexture.loadFromFile(RESOURCHES_PATH + "\\SnakeTurnBody.png"));
		assert(game.snakeTailTexture.loadFromFile(RESOURCHES_PATH + "\\SnakeTail.png"));

		assert(game.font.loadFromFile(RESOURCHES_PATH + "\\Fonts\\Roboto-Bold.ttf"));

		assert(game.backgroundSoundBuffer.loadFromFile(RESOURCHES_PATH + "\\Clinthammer__Background_Music.wav"));
		assert(game.inputEnterMenuSoundBuffer.loadFromFile(RESOURCHES_PATH + "\\Timgormly__Enter.wav"));
		assert(game.deathSoundBuffer.loadFromFile(RESOURCHES_PATH + "\\Maodin204__Lose.wav"));
		assert(game.appleEatenSoundBuffer.loadFromFile(RESOURCHES_PATH + "\\Owlstorm__Snake_hit.wav"));
		assert(game.inputMoveMenuSoundBuffer.loadFromFile(RESOURCHES_PATH + "\\Theevilsocks__menu-hover.wav"));
		
		game.background.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
		game.background.setFillColor(sf::Color::Black);
		game.background.setPosition(0.0f, 0.0f);

		InitUI(game.uiState, game.font);
		RestartGame(game);

		game.uiMenu.uiMenuSettings.backgroundSound.setBuffer(game.backgroundSoundBuffer);
		game.uiMenu.uiMenuSettings.inputEnterMenuSound.setBuffer(game.inputEnterMenuSoundBuffer);
		game.uiMenu.uiMenuSettings.deathSound.setBuffer(game.deathSoundBuffer);
		game.uiMenu.uiMenuSettings.appleEatenSound.setBuffer(game.appleEatenSoundBuffer);
		game.uiMenu.uiMenuSettings.inputMoveMenuSound.setBuffer(game.inputMoveMenuSoundBuffer);
	}

	void CheckCollisionWall(Game& game)
	{
		if ((game.snakeAll[0].position2D.x - SNAKE_SIZE < BORDER_SAFE_ZONE_LEFT) ||
			(game.snakeAll[0].position2D.x + SNAKE_SIZE > BORDER_SAFE_ZONE_RIGHT) ||
			(game.snakeAll[0].position2D.y - SNAKE_SIZE < BORDER_SAFE_ZONE_UP) ||
			(game.snakeAll[0].position2D.y + SNAKE_SIZE > BORDER_SAFE_ZONE_DOWN))
		{
			PlayDeathSound(game);
			game.isGameFinished = true;
			game.gameFinishTime = 0.0f;
			game.background.setFillColor(sf::Color::Black);
		}
	}

	void CheckCollisionSnake(Game& game)
	{
		for (int i = 1; i < game.snakeAll.size() - 1; ++i)
		{
			if ((game.snakeAll[0].position2D.x == game.snakeAll[i].position2D.x) &&
				(game.snakeAll[0].position2D.y == game.snakeAll[i].position2D.y))
			{
				PlayDeathSound(game);
				game.isGameFinished = true;
				game.gameFinishTime = 0.0f;
				game.background.setFillColor(sf::Color::Black);
				break;
			}
		}
	}

	void CheckFindCollisionApple(Game& game)
	{
		if ((game.apple.position2D.x == game.snakeAll[0].position2D.x) &&
			(game.apple.position2D.y == game.snakeAll[0].position2D.y))
		{
			game.numEatenApples += game.difficultyLevel.POINTS;
			UpdateUI(game.uiState, game);
			PlayAppleEatenSound(game);
			
			auto iter = game.snakeAll.cbegin();
			game.snakeAll.emplace(iter + 1, game.snakeAll[0]);
			CheckWhichTileShouldBetween(game);
			
			bool flagGetPosition = true;
			while (flagGetPosition)
			{
				game.apple.position2D = GetRandomPositionInScreen(game, 1, MAP_TILE_NUM_WIDTH - 2, 1, MAP_TILE_NUM_HEIGHT - 2);

				for (SnakeTile& snakeTile : game.snakeAll)
				{
					if ((fabs(game.apple.position2D.x - snakeTile.position2D.x) <= MIN_RESP_DISTANCE) &&
						(fabs(game.apple.position2D.y - snakeTile.position2D.y) <= MIN_RESP_DISTANCE))
					{
						break;
					}
					else if (&snakeTile == &game.snakeAll.back())
					{
						flagGetPosition = false;
						break;
					}
				}
			}
		}
	}

	void UpdateGame(Game& game, float deltaTime)
	{
		if (!(game.uiMenu.selectedMenuItemPressed & UIMenuPressedEnum::IsGameStartPressed))
		{
			UpdateUIMenu(game.uiMenu, game);
		}
		else if ((game.uiMenu.selectedMenuItemPressed & UIMenuPressedEnum::IsGameStartPressed) && 
				!(game.isGameFinished))
		{
			CheckCollisionWall(game);
			CheckCollisionSnake(game);

			if (!(game.isPushButtonWASD)) {
				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) &&
					(game.snakeAll[0].typeTileSnake != TypeTileSnake::SnakeHeadDirectionLeft))
				{
					game.snakeAll[0].typeTileSnake = TypeTileSnake::SnakeHeadDirectionRight;
					game.snakeAll[0].sprite.setRotation(180.f);
					game.isPushButtonWASD = true;
				}
				else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) &&
					(game.snakeAll[0].typeTileSnake != TypeTileSnake::SnakeHeadDirectionDown))
				{
					game.snakeAll[0].typeTileSnake = TypeTileSnake::SnakeHeadDirectionUp;
					game.snakeAll[0].sprite.setRotation(90.f);
					game.isPushButtonWASD = true;
				}
				else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)) &&
					(game.snakeAll[0].typeTileSnake != TypeTileSnake::SnakeHeadDirectionRight))
				{
					game.snakeAll[0].typeTileSnake = TypeTileSnake::SnakeHeadDirectionLeft;
					game.snakeAll[0].sprite.setRotation(0.f);
					game.isPushButtonWASD = true;
				}
				else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)) &&
					(game.snakeAll[0].typeTileSnake != TypeTileSnake::SnakeHeadDirectionUp))
				{
					game.snakeAll[0].typeTileSnake = TypeTileSnake::SnakeHeadDirectionDown;
					game.snakeAll[0].sprite.setRotation(270.f);
					game.isPushButtonWASD = true;
				}
			}
			
			game.gameFinishTime += deltaTime;

			if (game.gameFinishTime >= game.difficultyLevel.STEP_TIME)
			{
				CheckFindCollisionApple(game);
				UpdateSnakeTiles(game);
				game.gameFinishTime = 0.f;
			}
		}
		else if ((game.isGameFinished) && 
				(game.uiMenu.selectedMenuItemPressed & UIMenuPressedEnum::IsGameStartPressed))
		{
			UpdateUIMenu(game.uiMenu, game);
		}
	}

	void DrawGame(Game& game, sf::RenderWindow& window, float deltaTime)
	{
		window.draw(game.background);
		
		if (!(game.uiMenu.selectedMenuItemPressed & UIMenuPressedEnum::IsGameStartPressed))
		{
			DrawUIMenu(game.uiMenu, game, window);
		}
		else if (game.uiMenu.selectedMenuItemPressed & UIMenuPressedEnum::IsGameStartPressed)
		{
			if (!game.isGameFinished)
			{
				for (int i = 0; i < MAP_TILE_NUM_WIDTH; ++i)
				{
					for (int j = 0; j < MAP_TILE_NUM_HEIGHT; ++j)
					{
						DrawMapTile(game.mapTiles[i][j], window);
					}
				}

				for (SnakeTile& snakeTile : game.snakeAll)
				{
					DrawSnakeTile(snakeTile, window);
				}

				DrawApple(game.apple, window);
				DrawUI(game.uiState, window);
			}
			else if (game.isGameFinished)
			{
				DrawUIMenu(game.uiMenu, game, window);
				DrawUI(game.uiState, window);
			}
		}
	}
}