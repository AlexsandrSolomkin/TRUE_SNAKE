#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Constants.h"
#include "Game.h"

using namespace Snake;

int main()
{
    int seed = (int)time(nullptr);
    srand(seed);
    
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Snake");

    Game game;
    InitGame(game);
    DeserializeGame(game);
    sf::Clock gameClock;
    float lastTime = gameClock.getElapsedTime().asSeconds();

    while (window.isOpen())
    {
        sf::sleep(sf::milliseconds(16));

        float currentTime = gameClock.getElapsedTime().asSeconds();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)) ||
                (game.uiMenu.selectedMenuItemPressed & UIMenuPressedEnum::IsGameExitPressed))
            {
                window.close();
            }
        }

        UpdateGame(game, deltaTime);
        
        window.clear();
        
        DrawGame(game, window, deltaTime);
        window.display();

        PlayBackgroundSound(game);
    }

    return 0;
}