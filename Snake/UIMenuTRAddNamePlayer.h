#pragma once
#include "Constants.h"

namespace Snake
{
	enum UIMenuTRAddNamePlayerEnum
	{
		IsAddDefaultName = 1 << 0,
		IsAddNamePlayer = 1 << 1
	};

	enum UIMenuTRAddNamePlayerPressedEnum
	{
		IsAddDefaultNamePressed = 1 << 0,
		IsAddNamePlayerPressed = 1 << 1,

		IsSavePlayerName = 1 << 3
	};

	struct UIMenuTRAddNamePlayer
	{
		char selectedMenuTRAddNamePlayerItem = UIMenuTRAddNamePlayerEnum::IsAddDefaultName;
		char selectedMenuTRAddNamePlayerItemPressed = 0;

		sf::Text namePlayerText;

		sf::Text enterNameText;

		sf::Text buttonAddNamePlayerText;
		sf::Text buttonAddDefaultNameText;

		sf::Text nameText;
	};

	void AddCharNamePlayer(UIMenuTRAddNamePlayer& uiMenuTRAddNamePlayer, struct Game& game);
	void InitUIMenuTRAddNamePlayer(UIMenuTRAddNamePlayer& uiMenuTRAddNamePlayer, const sf::Font& font);
	void UpdateUIMenuTRAddNamePlayer(UIMenuTRAddNamePlayer& uiMenuTRAddNamePlayer, struct Game& game);
	void DrawUIMenuTRAddNamePlayer(UIMenuTRAddNamePlayer& uiMenuTRAddNamePlayer, sf::RenderWindow& window);
}
