#include "SFMLCanvas.h"
#include <iostream>

SFMLCanvas::SFMLCanvas(QWidget *parent) :
    QSFMLWidget(parent)
{

}

void SFMLCanvas::onInit()
{
    if (!m_tex.loadFromFile("Texture.png"))
    {
        std::cout << "Failed to find texture" << std::endl;
        return;
    }
    m_sprite.setTexture(m_tex);
    m_sprite.setPosition(sf::Vector2f(50, 50));
    m_sprite.setScale(0.5,0.5);
}

void SFMLCanvas::onUpdate()
{
    sf::RenderWindow::draw(m_sprite);
}
