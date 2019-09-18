#include "ExplosionGraphic.h"
#include "globals.h"

using namespace std;

ExplosionGraphic::ExplosionGraphic(sf::Vector2f v, string filename, sf::RenderWindow &w)
: m_shape(sf::Vector2f(BLOCK_SIDE, BLOCK_SIDE)), m_window(w)
{
	cout << "construct explosion" << endl;
	m_shape.setPosition(v);
	if (!m_texture.loadFromFile(filename)) {
		std::cout << "Failed to load texture from " << filename << std::endl;
	}
	m_shape.setTexture(&m_texture);
	m_window.draw(m_shape);
}