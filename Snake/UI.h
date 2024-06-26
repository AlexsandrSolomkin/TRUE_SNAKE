#pragma once
#include "SFML/Graphics.hpp"

namespace Snake
{
	struct UIState
	{
		bool isGameOverTextVisible = false;

		sf::Text scoreText;
	};

	void InitUI(UIState& uiState, const sf::Font& font);
	void UpdateUI(UIState& uiState, const struct Game& game);
	void DrawUI(UIState& uiState, sf::RenderWindow& window);
}