
#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

Game::Game(int width, int height) : m_window(sf::VideoMode(height, width), "Chicken or the Egg", sf::Style::Close | sf::Style::Titlebar)
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
		m_window.clear();
		m_window.draw(player);
		m_window.display();
	}
}