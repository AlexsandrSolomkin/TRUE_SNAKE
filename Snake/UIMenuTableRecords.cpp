#include "UIMenu.h"
#include "UIMenuTableRecords.h"
#include "Game.h"
#include <string>
#include <iostream>
#include <fstream>

using std::ios;

namespace Snake
{
	bool SerializeGame(const Game& game)
	{
		std::ofstream file(RECORD_TABLE_FILE, ios::out | ios::binary);

		if (file.is_open())
		{
			for (const auto& record : game.uiMenu.uiMenuTablePlayerResult.topPlayers)
			{
				file << record.namePlayerText.getString().toAnsiString() << " "
					<< record.result << std::endl;
			}

			file.close();
			
			return true;
		}
		return false;
	}

	bool DeserializeGame(Game& game)
	{
		std::ifstream file(RECORD_TABLE_FILE, ios::in | ios::binary);
		if (file.is_open())
		{
			int count = 0;

			std::string name;
			int score;

			while (file >> name >> score)
			{
				game.uiMenu.uiMenuTablePlayerResult.topPlayers[count].namePlayerText.setString(name);
				game.uiMenu.uiMenuTablePlayerResult.topPlayers[count].result = score;
				game.uiMenu.uiMenuTablePlayerResult.topPlayers[count++].resultText.setString(std::to_string(score));
			}

			file.close();

			return true;
		}
		return false;
	}

	void CheckColorUIMenuTablePlayerResultItem(sf::Text& text, UIMenuTablePlayerResult& uiMenuTablePlayerResult, const UIMenuTableRecordsEnum& uiMenuTableRecordsEnum)
	{
		if (uiMenuTablePlayerResult.selectedMenuTablePlayerResultItem & uiMenuTableRecordsEnum)
		{
			text.setFillColor(sf::Color::Green);
		}
		else
		{
			text.setFillColor(sf::Color::White);
		}
	}

	void CheckColorUIMenuTablePlayerResultAllItem(UIMenuTablePlayerResult& uiMenuTablePlayerResult)
	{
		CheckColorUIMenuTablePlayerResultItem(uiMenuTablePlayerResult.buttonPlayAgainText, uiMenuTablePlayerResult, UIMenuTableRecordsEnum::IsPlayAgain);
		CheckColorUIMenuTablePlayerResultItem(uiMenuTablePlayerResult.buttonMainMenuText, uiMenuTablePlayerResult, UIMenuTableRecordsEnum::IsMainMenu);
	}

	void CheckEnterPressedUIMenuTablePlayerResultItem(UIMenuTablePlayerResult& uiMenuTablePlayerResult, struct Game& game)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (uiMenuTablePlayerResult.selectedMenuTablePlayerResultItem & UIMenuTableRecordsEnum::IsPlayAgain)
			{
				game.uiMenu.selectedMenuItemPressed |= UIMenuPressedEnum::IsGameStartPressed;
				game.background.setFillColor(sf::Color(0, 153, 76));
			}
			else if (uiMenuTablePlayerResult.selectedMenuTablePlayerResultItem & UIMenuTableRecordsEnum::IsMainMenu)
			{
				game.uiMenu.selectedMenuItem = 0;
				game.uiMenu.selectedMenuItem |= UIMenuEnum::IsGameStart;
				game.uiMenu.selectedMenuItemPressed = 0;
			}

			game.isGameFinished = false;
			game.numEatenApples = 0;
			game.uiState.scoreText.setString("Score: " + std::to_string(game.numEatenApples));
			game.snakeAll = {};
			game.uiMenu.uiMenuTRAddNamePlayer.selectedMenuTRAddNamePlayerItemPressed = 0;
			
			InitSnakeTile(game);

			PlayInputEnterMenuSound(game);
			sf::sleep(sf::seconds(STEP_TIME_ACTIVATE_BUTTON));
		}
	}

	void InitUIMenuTablePlayerResult(UIMenuTablePlayerResult& uiMenuTablePlayerResult, const sf::Font& font)
	{
		for (int i = 0; i < NUM_MAIN_TABLE_RECORDS_PLAYERS_MENU; ++i)
		{
			PlayerResult playerResult;
			uiMenuTablePlayerResult.topPlayers.push_back(playerResult);
		}

		float PositionY = SCREEN_HEIGHT / 6.f;

		uiMenuTablePlayerResult.nameTableTopPlayersText.setFont(font);
		uiMenuTablePlayerResult.nameTableTopPlayersText.setCharacterSize(48);
		uiMenuTablePlayerResult.nameTableTopPlayersText.setFillColor(sf::Color(76, 153, 0));
		uiMenuTablePlayerResult.nameTableTopPlayersText.setString("TABLE RECORDS");
		uiMenuTablePlayerResult.nameTableTopPlayersText.setOrigin(GetTextOrigin(uiMenuTablePlayerResult.nameTableTopPlayersText, { 0.5f, 0.5f }));
		uiMenuTablePlayerResult.nameTableTopPlayersText.setPosition(SCREEN_WIDTH / 2.f, PositionY);

		int num = 0;
		float step = ((float)SCREEN_HEIGHT - 200.f) / ((float)NUM_MAIN_TABLE_RECORDS_PLAYERS_MENU + 1.f);
		
		for (PlayerResult& playerResult : uiMenuTablePlayerResult.topPlayers)
		{
			PositionY += step;

			playerResult.positionInTableText.setFont(font);
			playerResult.positionInTableText.setCharacterSize(24);
			playerResult.positionInTableText.setFillColor(sf::Color::White);
			playerResult.positionInTableText.setString(std::to_string(++num) + ".");
			playerResult.positionInTableText.setOrigin(GetTextOrigin(playerResult.positionInTableText, { 0.5f, 0.5f }));
			playerResult.positionInTableText.setPosition(SCREEN_WIDTH / 6.f, PositionY);

			playerResult.namePlayerText.setFont(font);
			playerResult.namePlayerText.setCharacterSize(24);
			playerResult.namePlayerText.setFillColor(sf::Color::White);
			playerResult.namePlayerText.setString("XYZ");
			playerResult.namePlayerText.setOrigin(GetTextOrigin(playerResult.namePlayerText, { 0.f, 0.5f }));
			playerResult.namePlayerText.setPosition(SCREEN_WIDTH / 5.f, PositionY);

			playerResult.resultText.setFont(font);
			playerResult.resultText.setCharacterSize(24);
			playerResult.resultText.setFillColor(sf::Color::White);
			playerResult.resultText.setString("0");
			playerResult.resultText.setOrigin(GetTextOrigin(playerResult.resultText, { 0.5f, 0.5f }));
			playerResult.resultText.setPosition(SCREEN_WIDTH / 1.2f, PositionY);
		}

		uiMenuTablePlayerResult.buttonPlayAgainText.setFont(font);
		uiMenuTablePlayerResult.buttonPlayAgainText.setCharacterSize(24);
		uiMenuTablePlayerResult.buttonPlayAgainText.setFillColor(sf::Color::White);
		uiMenuTablePlayerResult.buttonPlayAgainText.setString("Play Again");
		uiMenuTablePlayerResult.buttonPlayAgainText.setOrigin(GetTextOrigin(uiMenuTablePlayerResult.buttonPlayAgainText, { 0.5f, 0.5f }));
		uiMenuTablePlayerResult.buttonPlayAgainText.setPosition(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT - 100);

		uiMenuTablePlayerResult.buttonMainMenuText.setFont(font);
		uiMenuTablePlayerResult.buttonMainMenuText.setCharacterSize(24);
		uiMenuTablePlayerResult.buttonMainMenuText.setFillColor(sf::Color::Green);
		uiMenuTablePlayerResult.buttonMainMenuText.setString("Main Menu");
		uiMenuTablePlayerResult.buttonMainMenuText.setOrigin(GetTextOrigin(uiMenuTablePlayerResult.buttonMainMenuText, { 0.5f, 0.5f }));
		uiMenuTablePlayerResult.buttonMainMenuText.setPosition(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT - 50);
	}

	void PushPlayerResult(struct Game& game)
	{
		if (game.uiMenu.uiMenuTablePlayerResult.topPlayers[game.uiMenu.uiMenuTablePlayerResult.topPlayers.size() - 1].result < game.numEatenApples)
		{
			game.uiMenu.uiMenuTablePlayerResult.topPlayers.back().result = game.numEatenApples;
			game.uiMenu.uiMenuTablePlayerResult.topPlayers.back().resultText.setString(std::to_string(game.numEatenApples));
			game.uiMenu.uiMenuTablePlayerResult.topPlayers.back().namePlayerText.setString(game.namePlayer);
		}
		else
		{
			return;
		}

		for (int i = game.uiMenu.uiMenuTablePlayerResult.topPlayers.size() - 2; i >= 0; --i)
		{
			if (game.uiMenu.uiMenuTablePlayerResult.topPlayers[i].result < game.uiMenu.uiMenuTablePlayerResult.topPlayers[i + 1].result)
			{
				PlayerResult playerResult = game.uiMenu.uiMenuTablePlayerResult.topPlayers[i];

				game.uiMenu.uiMenuTablePlayerResult.topPlayers[i].result = game.uiMenu.uiMenuTablePlayerResult.topPlayers[i + 1].result;
				game.uiMenu.uiMenuTablePlayerResult.topPlayers[i].resultText.setString(std::to_string(game.uiMenu.uiMenuTablePlayerResult.topPlayers[i + 1].result));
				game.uiMenu.uiMenuTablePlayerResult.topPlayers[i].namePlayerText.setString(game.uiMenu.uiMenuTablePlayerResult.topPlayers[i + 1].namePlayerText.getString());

				game.uiMenu.uiMenuTablePlayerResult.topPlayers[i + 1].result = playerResult.result;
				game.uiMenu.uiMenuTablePlayerResult.topPlayers[i + 1].resultText.setString(std::to_string(playerResult.result));
				game.uiMenu.uiMenuTablePlayerResult.topPlayers[i + 1].namePlayerText.setString(playerResult.namePlayerText.getString());
			}
			else
			{
				return;
			}
		}
	}

	void UpdateUIMenuTableRecords(UIMenuTablePlayerResult& uiMenuTablePlayerResult, struct Game& game)
	{
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)) &&
			(uiMenuTablePlayerResult.selectedMenuTablePlayerResultItem != UIMenuTableRecordsEnum::IsMainMenu))
		{
			uiMenuTablePlayerResult.selectedMenuTablePlayerResultItem *= 2;

			CheckColorUIMenuTablePlayerResultAllItem(uiMenuTablePlayerResult);

			PlayInputMoveMenuSound(game);
			sf::sleep(sf::seconds(STEP_TIME_ACTIVATE_BUTTON));
		}
		else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) &&
			(uiMenuTablePlayerResult.selectedMenuTablePlayerResultItem != UIMenuTableRecordsEnum::IsPlayAgain))
		{
			uiMenuTablePlayerResult.selectedMenuTablePlayerResultItem /= 2;

			CheckColorUIMenuTablePlayerResultAllItem(uiMenuTablePlayerResult);

			PlayInputMoveMenuSound(game);
			sf::sleep(sf::seconds(STEP_TIME_ACTIVATE_BUTTON));
		}

		CheckEnterPressedUIMenuTablePlayerResultItem(uiMenuTablePlayerResult, game);
	}

	void DrawEndGameInfo(UIMenuTablePlayerResult& uiMenuTablePlayerResult, sf::RenderWindow& window)
	{
		window.draw(uiMenuTablePlayerResult.nameTableTopPlayersText);

		int i = 0;

		for (PlayerResult& playerResult : uiMenuTablePlayerResult.topPlayers)
		{
			if (++i <= NUM_TABLE_RECORDS_PLAYERS_END_GAME)
			{
				window.draw(playerResult.positionInTableText);
				window.draw(playerResult.namePlayerText);
				window.draw(playerResult.resultText);
			}
			else
			{
				break;
			}
		}

		window.draw(uiMenuTablePlayerResult.buttonPlayAgainText);
		window.draw(uiMenuTablePlayerResult.buttonMainMenuText);
	}

	void DrawTablePlayerResult(UIMenuTablePlayerResult& uiMenuTablePlayerResult, sf::RenderWindow& window)
	{
		window.draw(uiMenuTablePlayerResult.nameTableTopPlayersText);

		for (PlayerResult& playerResult : uiMenuTablePlayerResult.topPlayers)
		{
			window.draw(playerResult.positionInTableText);
			window.draw(playerResult.namePlayerText);
			window.draw(playerResult.resultText);
		}

		window.draw(uiMenuTablePlayerResult.buttonMainMenuText);
	}
}