
#include "Game.h"
#include "rand.h"
#include "GameObject.h"
#include <iostream>
#include <string>

const int PLAYERSIZE = 100;
using namespace std;

Game::Game(int width, int height)
    : m_window(sf::VideoMode(height, width), "Chicken or the Egg", sf::Style::Close | sf::Style::Titlebar)
{
    std::cout << "Game Started!" << std::endl;
    m_level = 0;


    m_player = new Player(0,0,PLAYERSIZE);
    m_player->setTexture("content/sfml.png");
}

void Game::play()
{
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
            m_player->move(-0.1f, 0.0f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            m_player->move(0.0f, 0.1f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            m_player->move(0.1f, 0.0f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            m_player->move(0.0f, -0.1f);
        }
		m_window.clear();
		m_window.draw(m_player->getShape());
		m_window.display();
	}
}
//as of 10am, not fully implemented. Need enemy vector
void Game::drawGameBoardOne()
{
  int playerSpawn = randInt(4);

  switch (playerSpawn) {
    case 0:
      m_player->setPos(1,1);
      break;
    case 1:
      m_player->setPos(14,1);
      break;
    case 2:
      m_player->setPos(1,14);
      break;
    case 3:
      m_player->setPos(14,14);
      break;
    default:
      break;
      //cry
    }
    for(int i = 0; i < 36; i++)
    {
      //WallBlock constructor needs to be implemented !!!!
      //getUnbreakable()[i] = new WallBlock();
    }

    for(int i = 1; i < 15; i+=2)
    {
      for(int j = 1; j < 15; j+=2)
      {
        //getUnbreakable()[i].setPos(i,j);
      }
    }





}

std::vector<GameObject*> Game::getBreakable()
{
  return m_breakable;
}

std::vector<GameObject*> Game::getUnbreakable()
{
  return m_unbreakable;
}

int Game::getLevel()
{
  return m_level;
}

Player* Game::getPlayer()
{
  return m_player;
}

void Game::setBreakable(std::vector<GameObject*> objects)
{
  m_breakable = objects;
}

void Game::setUnbreakable(std::vector<GameObject*> objects)
{
  m_unbreakable = objects;
}

void Game::setLevel(int lvl)
{
  m_level = lvl;
}

void Game::setPlayer(Player* player)
{
  m_player = player;
}
