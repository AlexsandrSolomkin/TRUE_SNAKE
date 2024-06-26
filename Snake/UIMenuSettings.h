#pragma once
#include "Constants.h"
#include <SFML/Audio.hpp>

namespace Snake
{
	enum UIMenuSettingsEnum
	{
		IsSoundEffects = 1 << 0,
		IsMusic = 1 << 1,
		IsMainMenuS = 1 << 2
	};

	enum UIMenuSettingsPressedEnum
	{
		IsSoundEffectsPressed = 1 << 0,
		IsMusicPressed = 1 << 1,
		IsMainMenuSPressed = 1 << 2
	};

	struct UIMenuSettings
	{
		char selectedMenuSettingsItem = UIMenuSettingsEnum::IsSoundEffects;
		char selectedMenuSettingsItemPressed = (UIMenuSettingsPressedEnum::IsSoundEffectsPressed) | (UIMenuSettingsPressedEnum::IsMusicPressed);

		sf::Text nameSettingsText;

		sf::Text buttonSoundEffectsText;
		sf::Text buttonMusicText;
		sf::Text buttonMainMenuText;

		sf::Text statusSoundEffectsText;
		sf::Text statusMusicText;

		float timePlaybackgroundSound;

		sf::Sound backgroundSound;
		sf::Sound inputEnterMenuSound;
		sf::Sound deathSound;
		sf::Sound appleEatenSound;
		sf::Sound inputMoveMenuSound;
	};

	void PlayBackgroundSound(Game& game);
	void PlayInputEnterMenuSound(Game& game);
	void PlayDeathSound(Game& game);
	void PlayAppleEatenSound(Game& game);
	void PlayInputMoveMenuSound(Game& game);

	void InitUIMenuSettings(UIMenuSettings& uiMenuSettings, const sf::Font& font);
	void UpdateUIMenuSettings(UIMenuSettings& uiMenuSettings, struct Game& game);
	void DrawUIMenuSettings(UIMenuSettings& uiMenuSettings, sf::RenderWindow& window);
}