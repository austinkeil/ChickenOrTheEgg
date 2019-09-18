
#include "Game.h"
#include "rand.h"
#include "GameObject.h"
#include <iostream>
#include <string>
#include "globals.h"

using namespace std;

Game::Game(int width, int height)
    : m_window(sf::VideoMode(height, width), "Chicken or the Egg", sf::Style::Close | sf::Style::Titlebar)
{
    m_window.setFramerateLimit(10);
    m_boardWidth = width;
    m_blockWidth = PLAYERSIZE;
    std::cout << "Game Started!" << std::endl;
    m_level = 0;

    m_player = new Player(0,0,PLAYERSIZE, m_window, m_breakable, m_unbreakable);
    cout << "Calling setTexture" << endl;
    m_player->setTexture("content/chicken.png");
    m_player->spawn();
    generateUnbreakables();
    generateBreakables();
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
            m_player->move(sf::Vector2f(-m_blockWidth, 0));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            m_player->move(sf::Vector2f(0, m_blockWidth));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            m_player->move(sf::Vector2f(m_blockWidth, 0));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            m_player->move(sf::Vector2f(0, -m_blockWidth));
        }
        m_window.clear();
		m_window.draw(m_player->getShape());
        drawUnbreakables();
        drawBreakables();
		m_window.display();
	}
}
void Game::drawUnbreakables() {
    for (int i = 0; i < NUMBER_OF_BLOCKS; i++) {
        m_unbreakable[i]->drawMe();
    }
}

void Game::drawBreakables() {
    for (int i = 0; i < NUMBER_OF_BLOCKS; i++) {
        m_breakable[i]->drawMe();
    }
}

void Game::generateBreakables()
{
    m_breakable.resize(NUMBER_OF_BLOCKS);
    for (int i = 0; i < NUMBER_OF_BLOCKS; i++)
    {

        m_breakable[i] = new WallBlock(0, 0,PLAYERSIZE,m_window, m_breakable);
        m_breakable[i]->setTexture("content/breakable.jpeg");
    }
    // for each of the breakable blocks
    for (int j = 0; j < NUMBER_OF_BLOCKS; j++) {
        bool valid = false;
        bool taken = false;
        while (!valid) {
            sf::Vector2f v(randInt(BLOCK_COUNT-1)*100, randInt(BLOCK_COUNT-1)*100);
            for (int i = 0; i < NUMBER_OF_BLOCKS; i++) {
                sf::Vector2f b(m_breakable[i]->getPos());
                sf::Vector2f u(m_unbreakable[i]->getPos());

                if (b == v || u == v) {
                    taken = true;
                    break;
                }
            }
            if (taken) {
                break;
            }

            m_breakable[j]->setPos(v);
            m_breakable[j]->drawMe();
        }
    }
}
void Game::generateUnbreakables()
{
    m_unbreakable.resize(NUMBER_OF_BLOCKS);
    for (int i = 0; i < NUMBER_OF_BLOCKS; i++)
    {
      //WallBlock constructor needs to be implemented !!!!
      m_unbreakable[i] = new WallBlock(0, 0,PLAYERSIZE,m_window, m_unbreakable);
      m_unbreakable[i]->setTexture("content/unbreakable.jpeg");
    }

    int ndx = 0;
    int outOfBounds = false;
    for(int i = BLOCK_SIDE; i <BOARD_HEIGHT; i+=200)
    {
      if (outOfBounds){
        break;
      }
      for(int j = BLOCK_SIDE; j < BOARD_HEIGHT; j+=200)
      {
        if (ndx >= NUMBER_OF_BLOCKS) {
            outOfBounds = true;
            cout << "broke inner" << endl;
            break;
        }
        m_unbreakable[ndx]->setPos(i,j);
        m_unbreakable[ndx]->drawMe();
        ndx++;
      }
    }
}

std::vector<GameObject*> &Game::getBreakable()
{
  return m_breakable;
}

std::vector<GameObject*> &Game::getUnbreakable()
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