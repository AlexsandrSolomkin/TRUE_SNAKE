#include "UIMenu.h"
#include "Game.h"
#include <string>

namespace Snake
{
	void PlayBackgroundSound(Game& game)
	{
		if ((game.uiMenu.uiMenuSettings.selectedMenuSettingsItemPressed & UIMenuSettingsPressedEnum::IsMusicPressed) && 
			(game.uiMenu.uiMenuSettings.backgroundSound.getStatus() == sf::Sound::Status::Stopped))
		{
			game.uiMenu.uiMenuSettings.backgroundSound.play();
		}
	}
	
	void PlayInputEnterMenuSound(Game& game)
	{
		if ((game.uiMenu.uiMenuSettings.selectedMenuSettingsItemPressed & UIMenuSettingsPressedEnum::IsSoundEffectsPressed) &&
			(game.uiMenu.uiMenuSettings.inputEnterMenuSound.getStatus() == sf::Sound::Status::Stopped))
		{
			game.uiMenu.uiMenuSettings.inputEnterMenuSound.play();
		}
	}
	
	void PlayDeathSound(Game& game)
	{
		if ((game.uiMenu.uiMenuSettings.selectedMenuSettingsItemPressed & UIMenuSettingsPressedEnum::IsSoundEffectsPressed) &&
			(game.uiMenu.uiMenuSettings.deathSound.getStatus() == sf::Sound::Status::Stopped))
		{
			game.uiMenu.uiMenuSettings.deathSound.play();
		}
	}
	
	void PlayAppleEatenSound(Game& game)
	{
		if ((game.uiMenu.uiMenuSettings.selectedMenuSettingsItemPressed & UIMenuSettingsPressedEnum::IsSoundEffectsPressed) &&
			(game.uiMenu.uiMenuSettings.appleEatenSound.getStatus() == sf::Sound::Status::Stopped))
		{
			game.uiMenu.uiMenuSettings.appleEatenSound.play();
		}
	}
	
	void PlayInputMoveMenuSound(Game& game)
	{
		if ((game.uiMenu.uiMenuSettings.selectedMenuSettingsItemPressed & UIMenuSettingsPressedEnum::IsSoundEffectsPressed) &&
			(game.uiMenu.uiMenuSettings.inputMoveMenuSound.getStatus() == sf::Sound::Status::Stopped))
		{
			game.uiMenu.uiMenuSettings.inputMoveMenuSound.play();
		}
	}
	
	void CheckColorUIMenuSettingsItem(sf::Text& text, UIMenuSettings& uiMenuSettings, const UIMenuSettingsEnum& uiMenuSettingsEnum)
	{
		if (uiMenuSettings.selectedMenuSettingsItem & uiMenuSettingsEnum)
		{
			text.setFillColor(sf::Color::Green);
		}
		else
		{
			text.setFillColor(sf::Color::White);
		}
	}

	void CheckColorUIMenuSettingsAllItem(UIMenuSettings& uiMenuSettings)
	{
		CheckColorUIMenuSettingsItem(uiMenuSettings.buttonSoundEffectsText, uiMenuSettings, UIMenuSettingsEnum::IsSoundEffects);
		CheckColorUIMenuSettingsItem(uiMenuSettings.statusSoundEffectsText, uiMenuSettings, UIMenuSettingsEnum::IsSoundEffects);
		CheckColorUIMenuSettingsItem(uiMenuSettings.buttonMusicText, uiMenuSettings, UIMenuSettingsEnum::IsMusic);
		CheckColorUIMenuSettingsItem(uiMenuSettings.statusMusicText, uiMenuSettings, UIMenuSettingsEnum::IsMusic);
		CheckColorUIMenuSettingsItem(uiMenuSettings.buttonMainMenuText, uiMenuSettings, UIMenuSettingsEnum::IsMainMenuS);
	}
	
	void CheckEnterPressedUIMenuTablePlayerResultItem(UIMenuSettings& uiMenuSettings, struct Game& game)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (uiMenuSettings.selectedMenuSettingsItem & UIMenuSettingsEnum::IsSoundEffects)
			{
				if (game.uiMenu.uiMenuSettings.statusSoundEffectsText.getString() == "ON")
				{
					game.uiMenu.uiMenuSettings.statusSoundEffectsText.setString("OFF");
					game.uiMenu.uiMenuSettings.selectedMenuSettingsItemPressed &= ~(UIMenuSettingsPressedEnum::IsSoundEffectsPressed);
				}
				else if (game.uiMenu.uiMenuSettings.statusSoundEffectsText.getString() == "OFF")
				{
					game.uiMenu.uiMenuSettings.statusSoundEffectsText.setString("ON");
					game.uiMenu.uiMenuSettings.selectedMenuSettingsItemPressed |= UIMenuSettingsPressedEnum::IsSoundEffectsPressed;
				}
			}
			else if (uiMenuSettings.selectedMenuSettingsItem & UIMenuSettingsEnum::IsMusic)
			{
				if (game.uiMenu.uiMenuSettings.statusMusicText.getString() == "ON")
				{
					game.uiMenu.uiMenuSettings.statusMusicText.setString("OFF");
					game.uiMenu.uiMenuSettings.selectedMenuSettingsItemPressed &= ~(UIMenuSettingsPressedEnum::IsMusicPressed);
				}
				else if (game.uiMenu.uiMenuSettings.statusMusicText.getString() == "OFF")
				{
					game.uiMenu.uiMenuSettings.statusMusicText.setString("ON");
					game.uiMenu.uiMenuSettings.selectedMenuSettingsItemPressed |= UIMenuSettingsPressedEnum::IsMusicPressed;
				}
			}
			else if (uiMenuSettings.selectedMenuSettingsItem & UIMenuSettingsEnum::IsMainMenuS)
			{
				game.uiMenu.selectedMenuItemPressed = 0;
			}

			PlayInputEnterMenuSound(game);
			sf::sleep(sf::seconds(STEP_TIME_ACTIVATE_BUTTON));
		}
	}

	void InitUIMenuSettings(UIMenuSettings& uiMenuSettings, const sf::Font& font)
	{
		uiMenuSettings.nameSettingsText.setFont(font);
		uiMenuSettings.nameSettingsText.setCharacterSize(48);
		uiMenuSettings.nameSettingsText.setFillColor(sf::Color(76, 153, 0));
		uiMenuSettings.nameSettingsText.setString("SETTINGS");
		uiMenuSettings.nameSettingsText.setOrigin(GetTextOrigin(uiMenuSettings.nameSettingsText, { 0.5f, 0.5f }));

		uiMenuSettings.buttonSoundEffectsText.setFont(font);
		uiMenuSettings.buttonSoundEffectsText.setCharacterSize(24);
		CheckColorUIMenuSettingsItem(uiMenuSettings.buttonSoundEffectsText, uiMenuSettings, UIMenuSettingsEnum::IsSoundEffects);
		uiMenuSettings.buttonSoundEffectsText.setString("Sound effects");
		uiMenuSettings.buttonSoundEffectsText.setOrigin(GetTextOrigin(uiMenuSettings.buttonSoundEffectsText, { 0.5f, 0.5f }));

		uiMenuSettings.statusSoundEffectsText = uiMenuSettings.buttonSoundEffectsText;
		uiMenuSettings.statusSoundEffectsText.setString("ON");
		uiMenuSettings.statusSoundEffectsText.setOrigin(GetTextOrigin(uiMenuSettings.statusSoundEffectsText, { 0.f, 0.5f }));

		uiMenuSettings.buttonMusicText.setFont(font);
		uiMenuSettings.buttonMusicText.setCharacterSize(24);
		CheckColorUIMenuSettingsItem(uiMenuSettings.buttonMusicText, uiMenuSettings, UIMenuSettingsEnum::IsMusic);
		uiMenuSettings.buttonMusicText.setString("Music");
		uiMenuSettings.buttonMusicText.setOrigin(GetTextOrigin(uiMenuSettings.buttonMusicText, { 0.5f, 0.5f }));

		uiMenuSettings.statusMusicText = uiMenuSettings.buttonMusicText;
		uiMenuSettings.statusMusicText.setString("ON");
		uiMenuSettings.statusMusicText.setOrigin(GetTextOrigin(uiMenuSettings.statusMusicText, { 0.f, 0.5f }));

		uiMenuSettings.buttonMainMenuText.setFont(font);
		uiMenuSettings.buttonMainMenuText.setCharacterSize(24);
		CheckColorUIMenuSettingsItem(uiMenuSettings.buttonMainMenuText, uiMenuSettings, UIMenuSettingsEnum::IsMainMenuS);
		uiMenuSettings.buttonMainMenuText.setString("Main menu");
		uiMenuSettings.buttonMainMenuText.setOrigin(GetTextOrigin(uiMenuSettings.buttonMainMenuText, { 0.5f, 0.5f }));

		{
			uiMenuSettings.nameSettingsText.setPosition(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 4.f);

			const int step = 48;

			uiMenuSettings.buttonSoundEffectsText.setPosition(SCREEN_WIDTH / 2.5f, uiMenuSettings.nameSettingsText.getPosition().y + step * 2);
			uiMenuSettings.statusSoundEffectsText.setPosition(SCREEN_WIDTH / 1.5f, uiMenuSettings.buttonSoundEffectsText.getPosition().y);

			uiMenuSettings.buttonMusicText.setPosition(SCREEN_WIDTH / 2.5f, uiMenuSettings.buttonSoundEffectsText.getPosition().y + step);
			uiMenuSettings.statusMusicText.setPosition(SCREEN_WIDTH / 1.5f, uiMenuSettings.buttonMusicText.getPosition().y);

			uiMenuSettings.buttonMainMenuText.setPosition(SCREEN_WIDTH / 2.5f, uiMenuSettings.buttonMusicText.getPosition().y + step);
		}
	}

	void UpdateUIMenuSettings(UIMenuSettings& uiMenuSettings, struct Game& game)
	{
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)) &&
			(uiMenuSettings.selectedMenuSettingsItem != UIMenuSettingsEnum::IsMainMenuS))
		{
			uiMenuSettings.selectedMenuSettingsItem *= 2;

			CheckColorUIMenuSettingsAllItem(uiMenuSettings);

			PlayInputMoveMenuSound(game);
			sf::sleep(sf::seconds(STEP_TIME_ACTIVATE_BUTTON));
		}
		else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) &&
				(uiMenuSettings.selectedMenuSettingsItem != UIMenuSettingsEnum::IsSoundEffects))
		{
			uiMenuSettings.selectedMenuSettingsItem /= 2;

			CheckColorUIMenuSettingsAllItem(uiMenuSettings);

			PlayInputMoveMenuSound(game);
			sf::sleep(sf::seconds(STEP_TIME_ACTIVATE_BUTTON));
		}

		CheckEnterPressedUIMenuTablePlayerResultItem(uiMenuSettings, game);
	}

	void DrawUIMenuSettings(UIMenuSettings& uiMenuSettings, sf::RenderWindow& window)
	{
		window.draw(uiMenuSettings.nameSettingsText);

		window.draw(uiMenuSettings.buttonSoundEffectsText);
		window.draw(uiMenuSettings.statusSoundEffectsText);

		window.draw(uiMenuSettings.buttonMusicText);
		window.draw(uiMenuSettings.statusMusicText);

		window.draw(uiMenuSettings.buttonMainMenuText);
	}
}