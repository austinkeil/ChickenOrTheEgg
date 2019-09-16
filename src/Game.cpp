
#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

Game::Game(int width, int height)
    : m_window(sf::VideoMode(height, width), "Chicken or the Egg", sf::Style::Close | sf::Style::Titlebar),
    m_player(sf::Vector2f(200,200))
{
    std::cout << "Game Started!" << std::endl;
    m_level = 0;
#ifdef SFML_SYSTEM_WINDOWS
	__windowsHelper.setIcon(window.getSystemHandle());
#endif

}

void Game::play()
{
    sf::RectangleShape player(sf::Vector2f(200,200));
	player.setFillColor(sf::Color::Magenta);

	sf::Texture shapeTexture;
	shapeTexture.loadFromFile("content/sfml.png");
	player.setTexture(&shapeTexture);

	sf::Event event;

	while (m_window.isOpen())
	{
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
			else if (event.type == sf::Event::TextEntered) {
				if (event.text.unicode < 128)
					printf("%c\n", event.text.unicode);
			}
		}

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            player.move(-0.1f, 0.0f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            player.move(0.0f, 0.1f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            player.move(0.1f, 0.0f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            player.move(0.0f, -0.1f);
        }
		m_window.clear();
		m_window.draw(player);
		m_window.display();
	}
}