#include "UIMenu.h"
#include "Game.h"
#include <string>

namespace Snake
{
	void CheckColorUIMenuItem(sf::Text& text, UIMenu& uiMenu, const UIMenuEnum& uiMenuEnum)
	{
		if (uiMenu.selectedMenuItem & uiMenuEnum)
		{
			text.setFillColor(sf::Color::Green);
		}
		else
		{
			text.setFillColor(sf::Color::White);
		}
	}

	void CheckColorUIMenuAllItem(UIMenu& uiMenu)
	{
		CheckColorUIMenuItem(uiMenu.startGameText, uiMenu, UIMenuEnum::IsGameStart);
		CheckColorUIMenuItem(uiMenu.difficultyLevelGameText, uiMenu, UIMenuEnum::IsGameDifficultyLevel);
		CheckColorUIMenuItem(uiMenu.tableRecordsText, uiMenu, UIMenuEnum::IsGameTableRecords);
		CheckColorUIMenuItem(uiMenu.settingsText, uiMenu, UIMenuEnum::IsGameSettings);
		CheckColorUIMenuItem(uiMenu.exitText, uiMenu, UIMenuEnum::IsGameExit);
	}

	void CheckEnterPressedUIMenu(UIMenu& uiMenu, struct Game& game)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (uiMenu.selectedMenuItem & UIMenuEnum::IsGameStart)
			{
				uiMenu.selectedMenuItemPressed |= UIMenuPressedEnum::IsGameStartPressed;
				game.background.setFillColor(sf::Color(0, 153, 76));
			}
			else if (uiMenu.selectedMenuItem & UIMenuEnum::IsGameDifficultyLevel)
			{
				uiMenu.selectedMenuItemPressed |= UIMenuPressedEnum::IsGameDifficultyLevelPressed;
			}
			else if (uiMenu.selectedMenuItem & UIMenuEnum::IsGameTableRecords)
			{
				uiMenu.selectedMenuItemPressed |= UIMenuPressedEnum::IsGameTableRecordsPressed;
			}
			else if (uiMenu.selectedMenuItem & UIMenuEnum::IsGameSettings)
			{
				uiMenu.selectedMenuItemPressed |= UIMenuPressedEnum::IsGameSettingsPressed;
			}
			else if (uiMenu.selectedMenuItem & UIMenuEnum::IsGameExit)
			{
				uiMenu.selectedMenuItemPressed |= UIMenuPressedEnum::IsGameExitPressed;
			}

			PlayInputEnterMenuSound(game);
			sf::sleep(sf::seconds(STEP_TIME_ACTIVATE_BUTTON));
		}
	}

	void InitUIMenu(UIMenu& uiMenu, const sf::Font& font)
	{
		uiMenu.nameGameText.setFont(font);
		uiMenu.nameGameText.setCharacterSize(48);
		uiMenu.nameGameText.setFillColor(sf::Color(76, 153, 0));
		uiMenu.nameGameText.setString("SNAKE");
		uiMenu.nameGameText.setOrigin(GetTextOrigin(uiMenu.nameGameText, { 0.5f, 0.5f }));

		uiMenu.startGameText.setFont(font);
		uiMenu.startGameText.setCharacterSize(24);
		CheckColorUIMenuItem(uiMenu.startGameText, uiMenu, UIMenuEnum::IsGameStart);
		uiMenu.startGameText.setString("Start game");
		uiMenu.startGameText.setOrigin(GetTextOrigin(uiMenu.startGameText, { 0.5f, 0.5f }));

		uiMenu.difficultyLevelGameText.setFont(font);
		uiMenu.difficultyLevelGameText.setCharacterSize(24);
		CheckColorUIMenuItem(uiMenu.difficultyLevelGameText, uiMenu, UIMenuEnum::IsGameDifficultyLevel);
		uiMenu.difficultyLevelGameText.setString("Difficulty level game");
		uiMenu.difficultyLevelGameText.setOrigin(GetTextOrigin(uiMenu.difficultyLevelGameText, { 0.5f, 0.5f }));

		uiMenu.tableRecordsText.setFont(font);
		uiMenu.tableRecordsText.setCharacterSize(24);
		CheckColorUIMenuItem(uiMenu.tableRecordsText, uiMenu, UIMenuEnum::IsGameTableRecords);
		uiMenu.tableRecordsText.setString("Table records");
		uiMenu.tableRecordsText.setOrigin(GetTextOrigin(uiMenu.tableRecordsText, { 0.5f, 0.5f }));

		uiMenu.settingsText.setFont(font);
		uiMenu.settingsText.setCharacterSize(24);
		CheckColorUIMenuItem(uiMenu.settingsText, uiMenu, UIMenuEnum::IsGameSettings);
		uiMenu.settingsText.setString("Settings");
		uiMenu.settingsText.setOrigin(GetTextOrigin(uiMenu.settingsText, { 0.5f, 0.5f }));

		uiMenu.exitText.setFont(font);
		uiMenu.exitText.setCharacterSize(24);
		CheckColorUIMenuItem(uiMenu.exitText, uiMenu, UIMenuEnum::IsGameExit);
		uiMenu.exitText.setString("Exit");
		uiMenu.exitText.setOrigin(GetTextOrigin(uiMenu.exitText, { 0.5f, 0.5f }));

		{
			uiMenu.nameGameText.setPosition(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 4.f);
			const int step = 48;
			uiMenu.startGameText.setPosition(SCREEN_WIDTH / 2.f, uiMenu.nameGameText.getPosition().y + step * 2);
			uiMenu.difficultyLevelGameText.setPosition(SCREEN_WIDTH / 2.f, uiMenu.startGameText.getPosition().y + step);
			uiMenu.tableRecordsText.setPosition(SCREEN_WIDTH / 2.f, uiMenu.difficultyLevelGameText.getPosition().y + step);
			uiMenu.settingsText.setPosition(SCREEN_WIDTH / 2.f, uiMenu.tableRecordsText.getPosition().y + step);
			uiMenu.exitText.setPosition(SCREEN_WIDTH / 2.f, uiMenu.settingsText.getPosition().y + step);
		}

		InitUIMenuDifficultyLevel(uiMenu.uiMenuDifficultyLevel, font);
		InitUIMenuTablePlayerResult(uiMenu.uiMenuTablePlayerResult, font);
		InitUIMenuTRAddNamePlayer(uiMenu.uiMenuTRAddNamePlayer, font);
		InitUIMenuSettings(uiMenu.uiMenuSettings, font);
	}

	void UpdateUIMenu(UIMenu& uiMenu, struct Game& game)
	{
		//√À¿¬ÕŒ≈ Ã≈Õﬁ
		if (!(game.uiMenu.selectedMenuItemPressed))
		{
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)) &&
				(game.uiMenu.selectedMenuItem != UIMenuEnum::IsGameExit))
			{
				game.uiMenu.selectedMenuItem *= 2;

				CheckColorUIMenuAllItem(uiMenu);

				PlayInputMoveMenuSound(game);
				sf::sleep(sf::seconds(STEP_TIME_ACTIVATE_BUTTON));
			}
			else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) &&
				(game.uiMenu.selectedMenuItem != UIMenuEnum::IsGameStart))
			{
				game.uiMenu.selectedMenuItem /= 2;

				CheckColorUIMenuAllItem(uiMenu);
				
				PlayInputMoveMenuSound(game);
				sf::sleep(sf::seconds(STEP_TIME_ACTIVATE_BUTTON));
			}

			CheckEnterPressedUIMenu(uiMenu, game);
		}
		//¬€¡Œ– ”–Œ¬Õﬂ —ÀŒ∆ÕŒ—“»
		else if (game.uiMenu.selectedMenuItemPressed == UIMenuPressedEnum::IsGameDifficultyLevelPressed)
		{
			UpdateUIMenuDifficultyLevel(game.uiMenu.uiMenuDifficultyLevel, game);
		}
		//Õ¿—“–Œ… »
		else if (game.uiMenu.selectedMenuItemPressed == UIMenuPressedEnum::IsGameSettingsPressed)
		{
			UpdateUIMenuSettings(game.uiMenu.uiMenuSettings, game);
		}
		//Ã≈Õﬁ “¿¡À»÷€ –≈ Œ–ƒŒ¬ ¬  ŒÕ÷≈ »√–€
		else if ((game.uiMenu.uiMenuTRAddNamePlayer.selectedMenuTRAddNamePlayerItemPressed & UIMenuTRAddNamePlayerPressedEnum::IsSavePlayerName)
				||
				(game.uiMenu.selectedMenuItemPressed & UIMenuPressedEnum::IsGameTableRecordsPressed))
		{
			UpdateUIMenuTableRecords(game.uiMenu.uiMenuTablePlayerResult, game);

			CheckColorUIMenuAllItem(uiMenu);
		}
		//Ã≈Õﬁ ƒŒ¡¿¬À≈Õ»ﬂ »Ã≈Õ» ¬ “¿¡À»÷” –≈ Œ–ƒŒ¬
		else if ((game.uiMenu.uiMenuTRAddNamePlayer.selectedMenuTRAddNamePlayerItemPressed & UIMenuTRAddNamePlayerPressedEnum::IsAddNamePlayerPressed) &&
			!(game.uiMenu.uiMenuTRAddNamePlayer.selectedMenuTRAddNamePlayerItemPressed & UIMenuTRAddNamePlayerPressedEnum::IsSavePlayerName))
		{
			AddCharNamePlayer(game.uiMenu.uiMenuTRAddNamePlayer, game);
		}
		//Ã≈Õﬁ ƒŒ¡¿¬À≈Õ»ﬂ »Ã≈Õ» ¬ “¿¡À»÷” –≈ Œ–ƒŒ¬
		else if ((game.uiMenu.uiMenuTRAddNamePlayer.selectedMenuTRAddNamePlayerItemPressed == 0) &&
			!(game.uiMenu.uiMenuTRAddNamePlayer.selectedMenuTRAddNamePlayerItemPressed & UIMenuTRAddNamePlayerPressedEnum::IsSavePlayerName))
		{
			UpdateUIMenuTRAddNamePlayer(game.uiMenu.uiMenuTRAddNamePlayer, game);
		}
	}

	void DrawUIMenu(UIMenu& uiMenu, struct Game& game, sf::RenderWindow& window)
	{
		//√À¿¬ÕŒ≈ Ã≈Õﬁ
		if (!uiMenu.selectedMenuItemPressed)
		{
			window.draw(uiMenu.nameGameText);
			window.draw(uiMenu.startGameText);
			window.draw(uiMenu.difficultyLevelGameText);
			window.draw(uiMenu.tableRecordsText);
			window.draw(uiMenu.settingsText);
			window.draw(uiMenu.exitText);
		}
		//¬€¡Œ– ”–Œ¬Õﬂ —ÀŒ∆ÕŒ—“»
		else if (uiMenu.selectedMenuItemPressed == UIMenuPressedEnum::IsGameDifficultyLevelPressed)
		{
			DrawUIMenuDifficultyLevel(uiMenu.uiMenuDifficultyLevel, window);
		}
		//“¿¡À»÷¿ –≈ Œ–ƒŒ¬
		else if (uiMenu.selectedMenuItemPressed == UIMenuPressedEnum::IsGameTableRecordsPressed)
		{
			DrawTablePlayerResult(uiMenu.uiMenuTablePlayerResult, window);
		}
		//Õ¿—“–Œ… »
		else if (game.uiMenu.selectedMenuItemPressed == UIMenuPressedEnum::IsGameSettingsPressed)
		{
			DrawUIMenuSettings(game.uiMenu.uiMenuSettings, window);
		}
		//Ã≈Õﬁ “¿¡À»÷€ –≈ Œ–ƒŒ¬ ¬  ŒÕ÷≈ »√–€
		else if (game.uiMenu.uiMenuTRAddNamePlayer.selectedMenuTRAddNamePlayerItemPressed & UIMenuTRAddNamePlayerPressedEnum::IsSavePlayerName)
		{
			DrawEndGameInfo(uiMenu.uiMenuTablePlayerResult, window);
			DrawUI(game.uiState, window);
		}
		//Ã≈Õﬁ ƒŒ¡¿¬À≈Õ»ﬂ »Ã≈Õ» ¬ “¿¡À»÷” –≈ Œ–ƒŒ¬
		else if (!(game.uiMenu.selectedMenuItemPressed & UIMenuPressedEnum::IsGameExitPressed) && 
			(((game.uiMenu.uiMenuTRAddNamePlayer.selectedMenuTRAddNamePlayerItemPressed == 0) &&
			!(game.uiMenu.uiMenuTRAddNamePlayer.selectedMenuTRAddNamePlayerItemPressed & UIMenuTRAddNamePlayerPressedEnum::IsSavePlayerName))
			||
			(game.uiMenu.uiMenuTRAddNamePlayer.selectedMenuTRAddNamePlayerItemPressed & UIMenuTRAddNamePlayerPressedEnum::IsAddNamePlayerPressed)))
		{
			DrawUIMenuTRAddNamePlayer(game.uiMenu.uiMenuTRAddNamePlayer, window);
			DrawUI(game.uiState, window);
		}
	}
}