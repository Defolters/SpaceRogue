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
    if (!floorT.loadFromFile("floor.png"))
    {
        std::cout << "Failed to find texture" << std::endl;
        return;
    }
    if (!floor1T.loadFromFile("floor1.png"))
    {
        std::cout << "Failed to find texture" << std::endl;
        return;
    }
    if (!floor2T.loadFromFile("floor2.png"))
    {
        std::cout << "Failed to find texture" << std::endl;
        return;
    }
    if (!wallT.loadFromFile("wall.png"))
    {
        std::cout << "Failed to find texture" << std::endl;
        return;
    }
    /*m_sprite.setTexture(m_tex);
    m_sprite.setPosition(sf::Vector2f(50, 50));
    m_sprite.setScale(0.5,0.5);*/
    floorS.setTexture(floorT);
    floor1S.setTexture(floor1T);
    floor2S.setTexture(floor2T);
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
            else if (level[i][j] == 2)
            {
                tile = floor1S;
            }
            else if (level[i][j] == 3)
            {
                tile = floor2S;
            }
            tile.setPosition(i*24,j*24);
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
