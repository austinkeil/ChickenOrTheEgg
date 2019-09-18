
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
    m_window.setFramerateLimit(10);
    m_boardWidth = width;
    m_blockWidth = PLAYERSIZE;
    std::cout << "Game Started!" << std::endl;
    m_level = 0;

    m_player = new Player(0,0,PLAYERSIZE, m_window);
    cout << "Calling setTexture" << endl;
    m_player->setTexture("content/chicken.png");
    generateBoard();
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
        drawObjects();
		m_window.display();
	}
}
void Game::drawObjects() {
    for (int i = 0; i < NUMBER_OF_BLOCKS; i++) {
        m_breakable[i]->drawMe();
    }
    cout << "Finished drawing" << endl;
}
//as of 10am, not fully implemented. Need enemy vector
void Game::generateBoard()
{
  m_breakable.resize(NUMBER_OF_BLOCKS);

  int playerSpawn = randInt(4);

  switch (playerSpawn) {
    case 0:
      m_player->setPos(BLOCK_SIDE,BLOCK_SIDE);
      break;
    case 1:
      m_player->setPos(14 * BLOCK_SIDE,BLOCK_SIDE);
      break;
    case 2:
      m_player->setPos(BLOCK_SIDE,14 * BLOCK_SIDE);
      break;
    case 3:
      m_player->setPos(14 * BLOCK_SIDE,14 * BLOCK_SIDE);
      break;
    default:
      break;
      //cry
    }
    // WallBlock *b = new WallBlock("Wall",500,500,w,pups);
    // b->setColor(sf::Color::White);
    // b->


    for (int i = 0; i < NUMBER_OF_BLOCKS; i++)
    {
      //WallBlock constructor needs to be implemented !!!!
      m_breakable[i] = new WallBlock("Wall",0,0,m_window, m_breakable);
      m_breakable[i]->setColor(sf::Color::White);
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
        m_breakable[ndx]->setPos(i,j);
        m_breakable[ndx]->drawMe();
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
