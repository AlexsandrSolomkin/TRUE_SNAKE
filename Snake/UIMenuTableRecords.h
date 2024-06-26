#pragma once
#include "Constants.h"

namespace Snake
{
	enum UIMenuTableRecordsEnum
	{
		IsPlayAgain = 1 << 0,
		IsMainMenu = 1 << 1
	};

	enum UIMenuTableRecordsPressedEnum
	{
		IsPlayAgainPressed = 1 << 0,
		IsMainMenuPressed = 1 << 1
	};

	struct PlayerResult
	{
		sf::Text positionInTableText;
		sf::Text namePlayerText;
		int result = 0;
		sf::Text resultText;
	};

	struct UIMenuTablePlayerResult
	{
		char selectedMenuTablePlayerResultItem = UIMenuTableRecordsEnum::IsMainMenu;
		char selectedMenuTablePlayerResultItemPressed = 0;

		sf::Text nameTableTopPlayersText;
		std::vector<PlayerResult> topPlayers{};

		sf::Text buttonPlayAgainText;
		sf::Text buttonMainMenuText;
	};

	bool SerializeGame(const Game& game);
	bool DeserializeGame(Game& game);
	void InitUIMenuTablePlayerResult(UIMenuTablePlayerResult& uiMenuTablePlayerResult, const sf::Font& font);
	void PushPlayerResult(struct Game& game);
	void UpdateUIMenuTableRecords(UIMenuTablePlayerResult& uiMenuTablePlayerResult, struct Game& game);
	void DrawEndGameInfo(UIMenuTablePlayerResult& uiMenuTablePlayerResult, sf::RenderWindow& window);
	void DrawTablePlayerResult(UIMenuTablePlayerResult& uiMenuTablePlayerResult, sf::RenderWindow& window);
}