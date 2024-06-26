#pragma once
#include "Constants.h"

namespace Snake
{
	enum UIMenuDifficultyLevelEnum
	{
		IsLevel1 = 1 << 0,
		IsLevel2 = 1 << 1,
		IsLevel3 = 1 << 2,
		IsLevel4 = 1 << 3,
		IsLevel5 = 1 << 4,
		IsBack = 1 << 5
	};

	enum UIMenuDifficultyLevelPressedEnum
	{
		IsLevel1Pressed = 1 << 0,
		IsLevel2Pressed = 1 << 1,
		IsLevel3Pressed = 1 << 2,
		IsLevel4Pressed = 1 << 3,
		IsLevel5Pressed = 1 << 4,
		IsBackPressed = 1 << 5
	};

	struct UIMenuDifficultyLevel
	{
		char selectedDifficultyLevel = UIMenuDifficultyLevelEnum::IsLevel1;
		char selectedMenuDifficultyLevelItemPressed = 0;

		sf::Text nameMenuText;
		sf::Text nameLevel1Text;
		sf::Text nameLevel2Text;
		sf::Text nameLevel3Text;
		sf::Text nameLevel4Text;
		sf::Text nameLevel5Text;
		sf::Text backText;
	};

	void InitUIMenuDifficultyLevel(UIMenuDifficultyLevel& uiMenuDifficultyLevel, const sf::Font& font);
	void UpdateUIMenuDifficultyLevel(UIMenuDifficultyLevel& uiMenuDifficultyLevel, struct Game& game);
	void DrawUIMenuDifficultyLevel(UIMenuDifficultyLevel& uiMenuDifficultyLevel, sf::RenderWindow& window);
}
