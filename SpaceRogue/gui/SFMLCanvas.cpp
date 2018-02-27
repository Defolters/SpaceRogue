#include "SFMLCanvas.h"
#include <iostream>
#include <QDebug>
#include <QKeyEvent>

SFMLCanvas::SFMLCanvas(QWidget *parent) :
    QSFMLWidget(parent), map(nullptr)
{
    qDebug() << Q_FUNC_INFO;

}

void SFMLCanvas::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Ate key press" << event->key();
    /*if (!m_piece || m_paused)
            return;

        switch (event->key()) {
        case Qt::Key_Left:
            m_piece->moveLeft();
            break;
        case Qt::Key_Right:
            m_piece->moveRight();
            break;
        case Qt::Key_Up:
            m_piece->rotate();
            break;
        case Qt::Key_Down:
            m_piece->drop();
            landPiece();
            break;
        default:
            break;
        }

        update();*/
}

void SFMLCanvas::onInit()
{
    qDebug() << Q_FUNC_INFO;
    if (!floorT.loadFromFile("TreeAsh.bmp"))
    {
        std::cout << "Failed to find texture" << std::endl;
        return;
    }
    if (!wallT.loadFromFile("Water.bmp"))
    {
        std::cout << "Failed to find texture" << std::endl;
        return;
    }
    /*m_sprite.setTexture(m_tex);
    m_sprite.setPosition(sf::Vector2f(50, 50));
    m_sprite.setScale(0.5,0.5);*/
    floorS.setTexture(floorT);
    wallS.setTexture(wallT);


}

void SFMLCanvas::onUpdate()
{
//    qDebug() << Q_FUNC_INFO;

    // get map from map
    for (int i = 0; i < map->getWidth(); i++)
    {
        for (int j = 0; j < map->getHeight(); j++)
        {
            sf::Sprite tile = wallS;
            if (level[i][j] == 0)
            {
                tile = floorS;
            }
            tile.setPosition(i*21,j*21);
            sf::RenderWindow::draw(tile);
        }
    }
    // for set sprites for map

//    m_sprite.setPosition(m_sprite.getPosition().x+5, m_sprite.getPosition().y+5);
    //    sf::RenderWindow::draw(m_sprite);
}

void SFMLCanvas::setMap(Map *map)
{
    this->map = map;
    level = map->getLevel();

}
