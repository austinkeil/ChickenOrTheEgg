#include "Main.hpp"

int main()
{
	std::cout << "Hello World!" << std::endl;

	sf::RenderWindow window(sf::VideoMode(1024, 2048), "Chicken or the Egg", sf::Style::Close | sf::Style::Titlebar);
	sf::RectangleShape player(sf::Vector2f(200,200));
	player.setFillColor(sf::Color::Magenta);

#ifdef SFML_SYSTEM_WINDOWS
	__windowsHelper.setIcon(window.getSystemHandle());
#endif

	sf::CircleShape shape(window.getSize().x/2);
	shape.setFillColor(sf::Color::White);

	sf::Texture shapeTexture;
	shapeTexture.loadFromFile("content/sfml.png");
	shape.setTexture(&shapeTexture);

	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::TextEntered) {
				if (event.text.unicode < 128)
					printf("%c\n", event.text.unicode);
			}
		}

		window.clear();
		window.draw(player);
		window.display();
	}

	return 0;
}