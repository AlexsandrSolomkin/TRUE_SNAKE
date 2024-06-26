#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Constants.h"
#include "MapTile.h"
#include "Apple.h"
#include "SnakeTile.h"
#include "UI.h"
#include "UIMenu.h"

namespace Snake
{
	struct Game
	{
		Apple apple;
		std::vector<SnakeTile> snakeAll{};
		MapTile mapTiles[MAP_TILE_NUM_WIDTH][MAP_TILE_NUM_HEIGHT];

		int numEatenApples = 0;
		bool isGameFinished = false;
		float gameFinishTime = 0.0f;
		std::string namePlayer = "XYZ";

		DifficultyLevel difficultyLevel = DIFFICULTY_LEVEL_1;

		sf::RectangleShape background;
		UIState uiState;
		UIMenu uiMenu;

		sf::Texture appleTexture;
		sf::Texture mapGroundTexture_1;
		sf::Texture mapGroundTexture_2;
		sf::Texture mapWallTexture;
		sf::Texture snakeHeadTexture;
		sf::Texture snakeBodyTexture;
		sf::Texture snakeTurnBodyTexture;
		sf::Texture snakeTailTexture;

		sf::Font font;

		sf::SoundBuffer backgroundSoundBuffer;
		sf::SoundBuffer inputEnterMenuSoundBuffer;
		sf::SoundBuffer deathSoundBuffer;
		sf::SoundBuffer appleEatenSoundBuffer;
		sf::SoundBuffer inputMoveMenuSoundBuffer;
	};

	void InitGame(Game& game);
	void RestartGame(Game& game);
	void UpdateGame(Game& game, float deltaTime);
	void DrawGame(Game& game, sf::RenderWindow& window, float deltaTime);
}