#ifndef EXPLOSION_H
#define EXPLOSION_H
class ExplosionGraphic{
public:
    ExplosionGraphic(sf::Vector2f v, std::string filename, sf::RenderWindow &w);
private:
    sf::Texture m_texture;
    sf::RectangleShape m_shape;
	sf::RenderWindow &m_window;
};

#endif
