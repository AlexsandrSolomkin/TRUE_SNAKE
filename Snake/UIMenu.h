#pragma once
#include "SFML/Graphics.hpp"
#include "UIMenuDifficultyLevel.h"
#include "UIMenuTableRecords.h"
#include "UIMenuTRAddNamePlayer.h"
#include "UIMenuSettings.h"

namespace Snake
{
	enum UIMenuEnum
	{
		IsGameStart = 1 << 0,
		IsGameDifficultyLevel = 1 << 1,
		IsGameTableRecords = 1 << 2,
		IsGameSettings = 1 << 3,
		IsGameExit = 1 << 4
	};

	enum UIMenuPressedEnum
	{
		IsGameStartPressed = 1 << 0,
		IsGameDifficultyLevelPressed = 1 << 1,
		IsGameTableRecordsPressed = 1 << 2,
		IsGameSettingsPressed = 1 << 3,
		IsGameExitPressed = 1 << 4
	};
	
	struct UIMenu
	{
		char selectedMenuItem = UIMenuEnum::IsGameStart;
		char selectedMenuItemPressed = 0;

		sf::Text nameGameText;

		sf::Text startGameText;
		sf::Text difficultyLevelGameText;
		sf::Text tableRecordsText;
		sf::Text settingsText;
		sf::Text exitText;

		UIMenuDifficultyLevel uiMenuDifficultyLevel;
		UIMenuTablePlayerResult uiMenuTablePlayerResult;
		UIMenuTRAddNamePlayer uiMenuTRAddNamePlayer;
		UIMenuSettings uiMenuSettings;
	};

	void InitUIMenu(UIMenu& uiMenu, const sf::Font& font);
	void UpdateUIMenu(UIMenu& uiMenu, struct Game& game);
	void DrawUIMenu(UIMenu& uiMenu, struct Game& game, sf::RenderWindow& window);
}