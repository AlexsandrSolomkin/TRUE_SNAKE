#pragma once
#include <string>

namespace Snake
{
	struct DifficultyLevel
	{
		int POINTS;
		float STEP_TIME;
	};

	const std::string RESOURCHES_PATH = "Resources/";
	const std::string RECORD_TABLE_FILE = "record_table.bin";

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	
	const float INITIAL_SPEED = 100.f;
	const float TILE_SIZE = 20.f;
	const int MAP_TILE_NUM_WIDTH = 30;
	const int MAP_TILE_NUM_HEIGHT = 20;
	const float APPLE_SIZE = 20.f;
	const float SNAKE_SIZE = 20.f;
	const float MIN_RESP_DISTANCE = 40.f;

	const float STEP_TIME_ACTIVATE_BUTTON = 0.25f;

	const int BORDER_LEFT_RIGHT = 100;
	const int BORDER_UP_DOWN = 100;
	const int BORDER_SAFE_ZONE_RIGHT = 700 - (int)SNAKE_SIZE;
	const int BORDER_SAFE_ZONE_LEFT = 100;
	const int BORDER_SAFE_ZONE_DOWN = 500 - (int)SNAKE_SIZE;
	const int BORDER_SAFE_ZONE_UP = 100;
	
	const DifficultyLevel DIFFICULTY_LEVEL_1 = { 1, 0.2f };
	const DifficultyLevel DIFFICULTY_LEVEL_2 = { 2, 0.175f };
	const DifficultyLevel DIFFICULTY_LEVEL_3 = { 3, 0.15f };
	const DifficultyLevel DIFFICULTY_LEVEL_4 = { 4, 0.125f };
	const DifficultyLevel DIFFICULTY_LEVEL_5 = { 5, 0.1f };

	const int NUM_TABLE_RECORDS_PLAYERS_END_GAME = 5;
	const int NUM_MAIN_TABLE_RECORDS_PLAYERS_MENU = 10;
}
