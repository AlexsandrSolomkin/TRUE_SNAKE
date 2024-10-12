#include "UIMenu.h"
#include "Game.h"
#include <string>
#include <iostream>

namespace Snake
{
	void CheckColorUIMenuTRAddNamePlayerItem(sf::Text& text, UIMenuTRAddNamePlayer& uiMenuTRAddNamePlayer, const UIMenuTRAddNamePlayerEnum& uiMenuTRAddNamePlayerEnum)
	{
		if (uiMenuTRAddNamePlayer.selectedMenuTRAddNamePlayerItem & uiMenuTRAddNamePlayerEnum)
		{
			text.setFillColor(sf::Color::Green);
		}
		else
		{
			text.setFillColor(sf::Color::White);
		}
	}

	void CheckColorUIMenuTRAddNamePlayerAllItem(UIMenuTRAddNamePlayer& uiMenuTRAddNamePlayer)
	{
		CheckColorUIMenuTRAddNamePlayerItem(uiMenuTRAddNamePlayer.buttonAddDefaultNameText, uiMenuTRAddNamePlayer, UIMenuTRAddNamePlayerEnum::IsAddDefaultName);
		CheckColorUIMenuTRAddNamePlayerItem(uiMenuTRAddNamePlayer.buttonAddNamePlayerText, uiMenuTRAddNamePlayer, UIMenuTRAddNamePlayerEnum::IsAddNamePlayer);
	}

	char AddChar()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { return 65; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) { return 66; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) { return 67; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { return 68; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) { return 69; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) { return 70; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) { return 71; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) { return 72; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) { return 73; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) { return 74; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) { return 75; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) { return 76; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) { return 77; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) { return 78; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) { return 79; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) { return 80; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) { return 81; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) { return 82; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { return 83; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) { return 84; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) { return 85; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) { return 86; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { return 87; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) { return 88; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) { return 89; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) { return 90; }

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) { return 48; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) { return 49; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) { return 50; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) { return 51; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) { return 52; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) { return 53; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) { return 54; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) { return 55; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) { return 56; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) { return 57; }

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { return 95; }

		else { return 100; }
	}

	void AddCharNamePlayer(UIMenuTRAddNamePlayer& uiMenuTRAddNamePlayer, struct Game& game)
	{
		if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) &&
			!(uiMenuTRAddNamePlayer.selectedMenuTRAddNamePlayerItemPressed & UIMenuTRAddNamePlayerPressedEnum::IsSavePlayerName))
		{
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace)) &&
				(game.namePlayer.length() != 0))
			{
				game.namePlayer.pop_back();
			}
			else if ((AddChar() != 100) && (game.namePlayer.length() < 16))
			{
				game.namePlayer.push_back(AddChar());
			}

			uiMenuTRAddNamePlayer.nameText.setString(game.namePlayer);
			uiMenuTRAddNamePlayer.nameText.setOrigin(GetTextOrigin(uiMenuTRAddNamePlayer.nameText, { 0.5f, 0.5f }));
			sf::sleep(sf::seconds(0.05f));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			uiMenuTRAddNamePlayer.selectedMenuTRAddNamePlayerItemPressed |= UIMenuTRAddNamePlayerPressedEnum::IsSavePlayerName;
			PushPlayerResult(game);
			SerializeGame(game);
			game.namePlayer = "XYZ";
			PlayInputEnterMenuSound(game);
			sf::sleep(sf::seconds(STEP_TIME_ACTIVATE_BUTTON));
		}
	}

	void CheckEnterPressedUIMenuTRAddNamePlayerItem(UIMenuTRAddNamePlayer& uiMenuTRAddNamePlayer, struct Game& game)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (uiMenuTRAddNamePlayer.selectedMenuTRAddNamePlayerItem & UIMenuTRAddNamePlayerEnum::IsAddDefaultName)
			{
				uiMenuTRAddNamePlayer.selectedMenuTRAddNamePlayerItemPressed |= UIMenuTRAddNamePlayerPressedEnum::IsAddDefaultNamePressed;
				uiMenuTRAddNamePlayer.selectedMenuTRAddNamePlayerItemPressed |= UIMenuTRAddNamePlayerPressedEnum::IsSavePlayerName;
				PushPlayerResult(game);
			}
			else if (uiMenuTRAddNamePlayer.selectedMenuTRAddNamePlayerItem & UIMenuTRAddNamePlayerEnum::IsAddNamePlayer)
			{
				uiMenuTRAddNamePlayer.selectedMenuTRAddNamePlayerItemPressed |= UIMenuTRAddNamePlayerPressedEnum::IsAddNamePlayerPressed;
			}

			PlayInputEnterMenuSound(game);
			sf::sleep(sf::seconds(STEP_TIME_ACTIVATE_BUTTON));
		}
	}

	void InitUIMenuTRAddNamePlayer(UIMenuTRAddNamePlayer& uiMenuTRAddNamePlayer, const sf::Font& font)
	{
		uiMenuTRAddNamePlayer.enterNameText.setFont(font);
		uiMenuTRAddNamePlayer.enterNameText.setCharacterSize(48);
		uiMenuTRAddNamePlayer.enterNameText.setFillColor(sf::Color(76, 153, 0));
		uiMenuTRAddNamePlayer.enterNameText.setString("ENTER NAME");
		uiMenuTRAddNamePlayer.enterNameText.setOrigin(GetTextOrigin(uiMenuTRAddNamePlayer.enterNameText, { 0.5f, 0.5f }));
		uiMenuTRAddNamePlayer.enterNameText.setPosition(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 4.f);

		const int step = 48;

		uiMenuTRAddNamePlayer.buttonAddDefaultNameText.setFont(font);
		uiMenuTRAddNamePlayer.buttonAddDefaultNameText.setCharacterSize(24);
		uiMenuTRAddNamePlayer.buttonAddDefaultNameText.setFillColor(sf::Color::Green);
		uiMenuTRAddNamePlayer.buttonAddDefaultNameText.setString("NO");
		uiMenuTRAddNamePlayer.buttonAddDefaultNameText.setOrigin(GetTextOrigin(uiMenuTRAddNamePlayer.buttonAddDefaultNameText, { 0.5f, 0.5f }));
		uiMenuTRAddNamePlayer.buttonAddDefaultNameText.setPosition(SCREEN_WIDTH / 2.f, uiMenuTRAddNamePlayer.enterNameText.getPosition().y + step * 2);

		uiMenuTRAddNamePlayer.buttonAddNamePlayerText.setFont(font);
		uiMenuTRAddNamePlayer.buttonAddNamePlayerText.setCharacterSize(24);
		uiMenuTRAddNamePlayer.buttonAddNamePlayerText.setFillColor(sf::Color::White);
		uiMenuTRAddNamePlayer.buttonAddNamePlayerText.setString("YES");
		uiMenuTRAddNamePlayer.buttonAddNamePlayerText.setOrigin(GetTextOrigin(uiMenuTRAddNamePlayer.buttonAddNamePlayerText, { 0.5f, 0.5f }));
		uiMenuTRAddNamePlayer.buttonAddNamePlayerText.setPosition(SCREEN_WIDTH / 2.f, uiMenuTRAddNamePlayer.buttonAddDefaultNameText.getPosition().y + step);

		uiMenuTRAddNamePlayer.nameText.setFont(font);
		uiMenuTRAddNamePlayer.nameText.setCharacterSize(24);
		uiMenuTRAddNamePlayer.nameText.setFillColor(sf::Color::White);
		uiMenuTRAddNamePlayer.nameText.setString("");
		uiMenuTRAddNamePlayer.nameText.setOrigin(GetTextOrigin(uiMenuTRAddNamePlayer.nameText, { 0.5f, 0.5f }));
		uiMenuTRAddNamePlayer.nameText.setPosition(SCREEN_WIDTH / 2.f, uiMenuTRAddNamePlayer.buttonAddDefaultNameText.getPosition().y);
	}

	void UpdateUIMenuTRAddNamePlayer(UIMenuTRAddNamePlayer& uiMenuTRAddNamePlayer, struct Game& game)
	{
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)) &&
			(uiMenuTRAddNamePlayer.selectedMenuTRAddNamePlayerItem != UIMenuTRAddNamePlayerEnum::IsAddNamePlayer))
		{
			uiMenuTRAddNamePlayer.selectedMenuTRAddNamePlayerItem *= 2;

			CheckColorUIMenuTRAddNamePlayerAllItem(uiMenuTRAddNamePlayer);

			PlayInputMoveMenuSound(game);
			sf::sleep(sf::seconds(STEP_TIME_ACTIVATE_BUTTON));
		}
		else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) &&
			(uiMenuTRAddNamePlayer.selectedMenuTRAddNamePlayerItem != UIMenuTRAddNamePlayerEnum::IsAddDefaultName))
		{
			uiMenuTRAddNamePlayer.selectedMenuTRAddNamePlayerItem /= 2;

			CheckColorUIMenuTRAddNamePlayerAllItem(uiMenuTRAddNamePlayer);

			PlayInputMoveMenuSound(game);
			sf::sleep(sf::seconds(STEP_TIME_ACTIVATE_BUTTON));
		}

		CheckEnterPressedUIMenuTRAddNamePlayerItem(uiMenuTRAddNamePlayer, game);
	}

	void DrawUIMenuTRAddNamePlayer(UIMenuTRAddNamePlayer& uiMenuTRAddNamePlayer, sf::RenderWindow& window)
	{
		window.draw(uiMenuTRAddNamePlayer.enterNameText);

		if (uiMenuTRAddNamePlayer.selectedMenuTRAddNamePlayerItemPressed == 0)
		{
			window.draw(uiMenuTRAddNamePlayer.buttonAddDefaultNameText);
		}
		else if (uiMenuTRAddNamePlayer.selectedMenuTRAddNamePlayerItemPressed & UIMenuTRAddNamePlayerPressedEnum::IsAddNamePlayerPressed)
		{
			window.draw(uiMenuTRAddNamePlayer.nameText);
		}

		window.draw(uiMenuTRAddNamePlayer.buttonAddNamePlayerText);
	}
}
