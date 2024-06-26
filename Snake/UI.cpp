#include "UI.h"
#include "Game.h"
#include <string>

namespace Snake
{
	void InitUI(UIState& uiState, const sf::Font& font)
	{
		uiState.scoreText.setFont(font);
		uiState.scoreText.setCharacterSize(20);
		uiState.scoreText.setFillColor(sf::Color::White);
		uiState.scoreText.setPosition(SCREEN_WIDTH - 100.f, 10.f);
		uiState.scoreText.setString("Score: 0");
	}

	void UpdateUI(UIState& uiState, const struct Game& game)
	{
		uiState.scoreText.setString("Score: " + std::to_string(game.numEatenApples));
	}

	void DrawUI(UIState& uiState, sf::RenderWindow& window)
	{
		window.draw(uiState.scoreText);
	}
}
