#include "UIMenu.h"
#include "Game.h"
#include <string>

namespace Snake
{
	void CheckColorUIMenuDifficultyLevelItem(sf::Text& text, UIMenuDifficultyLevel& uiMenuDifficultyLevel, const UIMenuDifficultyLevelEnum& uiMenuDifficultyLevelEnum)
	{
		if (uiMenuDifficultyLevel.selectedDifficultyLevel & uiMenuDifficultyLevelEnum)
		{
			text.setFillColor(sf::Color::Green);
		}
		else
		{
			text.setFillColor(sf::Color::White);
		}
	}

	void CheckColorUIMenuDifficultyLevelAllItem(UIMenuDifficultyLevel& uiMenuDifficultyLevel)
	{
		CheckColorUIMenuDifficultyLevelItem(uiMenuDifficultyLevel.nameLevel1Text, uiMenuDifficultyLevel, UIMenuDifficultyLevelEnum::IsLevel1);
		CheckColorUIMenuDifficultyLevelItem(uiMenuDifficultyLevel.nameLevel2Text, uiMenuDifficultyLevel, UIMenuDifficultyLevelEnum::IsLevel2);
		CheckColorUIMenuDifficultyLevelItem(uiMenuDifficultyLevel.nameLevel3Text, uiMenuDifficultyLevel, UIMenuDifficultyLevelEnum::IsLevel3);
		CheckColorUIMenuDifficultyLevelItem(uiMenuDifficultyLevel.nameLevel4Text, uiMenuDifficultyLevel, UIMenuDifficultyLevelEnum::IsLevel4);
		CheckColorUIMenuDifficultyLevelItem(uiMenuDifficultyLevel.nameLevel5Text, uiMenuDifficultyLevel, UIMenuDifficultyLevelEnum::IsLevel5);
		CheckColorUIMenuDifficultyLevelItem(uiMenuDifficultyLevel.backText, uiMenuDifficultyLevel, UIMenuDifficultyLevelEnum::IsBack);
	}

	void CheckEnterPressedUIMenuDifficultyLevel(UIMenuDifficultyLevel& uiMenuDifficultyLevel, struct Game& game)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (uiMenuDifficultyLevel.selectedDifficultyLevel & UIMenuDifficultyLevelEnum::IsLevel1)
			{
				uiMenuDifficultyLevel.selectedMenuDifficultyLevelItemPressed |= UIMenuDifficultyLevelPressedEnum::IsLevel1Pressed;
				game.difficultyLevel = DIFFICULTY_LEVEL_1;
			}
			else if (uiMenuDifficultyLevel.selectedDifficultyLevel & UIMenuDifficultyLevelEnum::IsLevel2)
			{
				uiMenuDifficultyLevel.selectedMenuDifficultyLevelItemPressed |= UIMenuDifficultyLevelPressedEnum::IsLevel2Pressed;
				game.difficultyLevel = DIFFICULTY_LEVEL_2;
			}
			else if (uiMenuDifficultyLevel.selectedDifficultyLevel & UIMenuDifficultyLevelEnum::IsLevel3)
			{
				uiMenuDifficultyLevel.selectedMenuDifficultyLevelItemPressed |= UIMenuDifficultyLevelPressedEnum::IsLevel3Pressed;
				game.difficultyLevel = DIFFICULTY_LEVEL_3;
			}
			else if (uiMenuDifficultyLevel.selectedDifficultyLevel & UIMenuDifficultyLevelEnum::IsLevel4)
			{
				uiMenuDifficultyLevel.selectedMenuDifficultyLevelItemPressed |= UIMenuDifficultyLevelPressedEnum::IsLevel4Pressed;
				game.difficultyLevel = DIFFICULTY_LEVEL_4;
			}
			else if (uiMenuDifficultyLevel.selectedDifficultyLevel & UIMenuDifficultyLevelEnum::IsLevel5)
			{
				uiMenuDifficultyLevel.selectedMenuDifficultyLevelItemPressed |= UIMenuDifficultyLevelPressedEnum::IsLevel5Pressed;
				game.difficultyLevel = DIFFICULTY_LEVEL_5;
			}
			else if (uiMenuDifficultyLevel.selectedDifficultyLevel & UIMenuDifficultyLevelEnum::IsBack)
			{
				game.uiMenu.selectedMenuItemPressed = 0;
				uiMenuDifficultyLevel.selectedDifficultyLevel = UIMenuDifficultyLevelEnum::IsLevel1;
				uiMenuDifficultyLevel.selectedMenuDifficultyLevelItemPressed = 0;

				CheckColorUIMenuDifficultyLevelAllItem(uiMenuDifficultyLevel);
			}

			PlayInputEnterMenuSound(game);
			sf::sleep(sf::seconds(STEP_TIME_ACTIVATE_BUTTON));
		}
	}

	void InitUIMenuDifficultyLevel(UIMenuDifficultyLevel& uiMenuDifficultyLevel, const sf::Font& font)
	{
		uiMenuDifficultyLevel.nameMenuText.setFont(font);
		uiMenuDifficultyLevel.nameMenuText.setCharacterSize(48);
		uiMenuDifficultyLevel.nameMenuText.setFillColor(sf::Color(76, 153, 0));
		uiMenuDifficultyLevel.nameMenuText.setString("DIFFICULTY LEVEL");
		uiMenuDifficultyLevel.nameMenuText.setOrigin(GetTextOrigin(uiMenuDifficultyLevel.nameMenuText, { 0.5f, 0.5f }));

		uiMenuDifficultyLevel.nameLevel1Text.setFont(font);
		uiMenuDifficultyLevel.nameLevel1Text.setCharacterSize(24);
		CheckColorUIMenuDifficultyLevelItem(uiMenuDifficultyLevel.nameLevel1Text, uiMenuDifficultyLevel, UIMenuDifficultyLevelEnum::IsLevel1);
		uiMenuDifficultyLevel.nameLevel1Text.setString("Easy");
		uiMenuDifficultyLevel.nameLevel1Text.setOrigin(GetTextOrigin(uiMenuDifficultyLevel.nameLevel1Text, { 0.5f, 0.5f }));

		uiMenuDifficultyLevel.nameLevel2Text.setFont(font);
		uiMenuDifficultyLevel.nameLevel2Text.setCharacterSize(24);
		CheckColorUIMenuDifficultyLevelItem(uiMenuDifficultyLevel.nameLevel2Text, uiMenuDifficultyLevel, UIMenuDifficultyLevelEnum::IsLevel2);
		uiMenuDifficultyLevel.nameLevel2Text.setString("Normal");
		uiMenuDifficultyLevel.nameLevel2Text.setOrigin(GetTextOrigin(uiMenuDifficultyLevel.nameLevel2Text, { 0.5f, 0.5f }));

		uiMenuDifficultyLevel.nameLevel3Text.setFont(font);
		uiMenuDifficultyLevel.nameLevel3Text.setCharacterSize(24);
		CheckColorUIMenuDifficultyLevelItem(uiMenuDifficultyLevel.nameLevel3Text, uiMenuDifficultyLevel, UIMenuDifficultyLevelEnum::IsLevel3);
		uiMenuDifficultyLevel.nameLevel3Text.setString("Hard");
		uiMenuDifficultyLevel.nameLevel3Text.setOrigin(GetTextOrigin(uiMenuDifficultyLevel.nameLevel3Text, { 0.5f, 0.5f }));

		uiMenuDifficultyLevel.nameLevel4Text.setFont(font);
		uiMenuDifficultyLevel.nameLevel4Text.setCharacterSize(24);
		CheckColorUIMenuDifficultyLevelItem(uiMenuDifficultyLevel.nameLevel4Text, uiMenuDifficultyLevel, UIMenuDifficultyLevelEnum::IsLevel4);
		uiMenuDifficultyLevel.nameLevel4Text.setString("Very Hard");
		uiMenuDifficultyLevel.nameLevel4Text.setOrigin(GetTextOrigin(uiMenuDifficultyLevel.nameLevel4Text, { 0.5f, 0.5f }));

		uiMenuDifficultyLevel.nameLevel5Text.setFont(font);
		uiMenuDifficultyLevel.nameLevel5Text.setCharacterSize(24);
		CheckColorUIMenuDifficultyLevelItem(uiMenuDifficultyLevel.nameLevel5Text, uiMenuDifficultyLevel, UIMenuDifficultyLevelEnum::IsLevel5);
		uiMenuDifficultyLevel.nameLevel5Text.setString("True Snake");
		uiMenuDifficultyLevel.nameLevel5Text.setOrigin(GetTextOrigin(uiMenuDifficultyLevel.nameLevel5Text, { 0.5f, 0.5f }));

		uiMenuDifficultyLevel.backText.setFont(font);
		uiMenuDifficultyLevel.backText.setCharacterSize(24);
		CheckColorUIMenuDifficultyLevelItem(uiMenuDifficultyLevel.backText, uiMenuDifficultyLevel, UIMenuDifficultyLevelEnum::IsBack);
		uiMenuDifficultyLevel.backText.setString("Back");
		uiMenuDifficultyLevel.backText.setOrigin(GetTextOrigin(uiMenuDifficultyLevel.backText, { 0.5f, 0.5f }));

		{
			uiMenuDifficultyLevel.nameMenuText.setPosition(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 4.f);
			const int step = 48;
			uiMenuDifficultyLevel.nameLevel1Text.setPosition(SCREEN_WIDTH / 2.f, uiMenuDifficultyLevel.nameMenuText.getPosition().y + step * 2);
			uiMenuDifficultyLevel.nameLevel2Text.setPosition(SCREEN_WIDTH / 2.f, uiMenuDifficultyLevel.nameLevel1Text.getPosition().y + step);
			uiMenuDifficultyLevel.nameLevel3Text.setPosition(SCREEN_WIDTH / 2.f, uiMenuDifficultyLevel.nameLevel2Text.getPosition().y + step);
			uiMenuDifficultyLevel.nameLevel4Text.setPosition(SCREEN_WIDTH / 2.f, uiMenuDifficultyLevel.nameLevel3Text.getPosition().y + step);
			uiMenuDifficultyLevel.nameLevel5Text.setPosition(SCREEN_WIDTH / 2.f, uiMenuDifficultyLevel.nameLevel4Text.getPosition().y + step);
			uiMenuDifficultyLevel.backText.setPosition(SCREEN_WIDTH / 2.f, uiMenuDifficultyLevel.nameLevel5Text.getPosition().y + step);
		}
	}

	void UpdateUIMenuDifficultyLevel(UIMenuDifficultyLevel& uiMenuDifficultyLevel, struct Game& game)
	{
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)) &&
			(uiMenuDifficultyLevel.selectedDifficultyLevel != UIMenuDifficultyLevelEnum::IsBack))
		{
			uiMenuDifficultyLevel.selectedDifficultyLevel *= 2;

			CheckColorUIMenuDifficultyLevelAllItem(uiMenuDifficultyLevel);

			PlayInputMoveMenuSound(game);
			sf::sleep(sf::seconds(STEP_TIME_ACTIVATE_BUTTON));
		}
		else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) &&
			(uiMenuDifficultyLevel.selectedDifficultyLevel != UIMenuDifficultyLevelEnum::IsLevel1))
		{
			uiMenuDifficultyLevel.selectedDifficultyLevel /= 2;

			CheckColorUIMenuDifficultyLevelAllItem(uiMenuDifficultyLevel);

			PlayInputMoveMenuSound(game);
			sf::sleep(sf::seconds(STEP_TIME_ACTIVATE_BUTTON));
		}

		CheckEnterPressedUIMenuDifficultyLevel(uiMenuDifficultyLevel, game);
	}

	void DrawUIMenuDifficultyLevel(UIMenuDifficultyLevel& uiMenuDifficultyLevel, sf::RenderWindow& window)
	{
		window.draw(uiMenuDifficultyLevel.nameMenuText);
		window.draw(uiMenuDifficultyLevel.nameLevel1Text);
		window.draw(uiMenuDifficultyLevel.nameLevel2Text);
		window.draw(uiMenuDifficultyLevel.nameLevel3Text);
		window.draw(uiMenuDifficultyLevel.nameLevel4Text);
		window.draw(uiMenuDifficultyLevel.nameLevel5Text);
		window.draw(uiMenuDifficultyLevel.backText);
	}
}