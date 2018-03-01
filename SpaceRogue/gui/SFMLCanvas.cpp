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
    if (!playerT.loadFromFile("player.png"))
    {
        std::cout << "Failed to find texture" << std::endl;
        return;
    }
    if (!startT.loadFromFile("start.png"))
    {
        std::cout << "Failed to find texture" << std::endl;
        return;
    }
    if (!stairsT.loadFromFile("stairs.png"))
    {
        std::cout << "Failed to find texture" << std::endl;
        return;
    }

    floorS.setTexture(floorT);
    floor1S.setTexture(floor1T);
    floor2S.setTexture(floor2T);
    wallS.setTexture(wallT);
    playerS.setTexture(playerT);
    startS.setTexture(startT);
    stairsS.setTexture(stairsT);
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

    startS.setPosition(map->getPlayerStartPosition().x*24, map->getPlayerStartPosition().y*24);
    sf::RenderWindow::draw(startS);

    playerS.setPosition(map->getPlayer()->getPosition().x*24,map->getPlayer()->getPosition().y*24);
    sf::RenderWindow::draw(playerS);

    stairsS.setPosition(map->getStairsPosition().x*24, map->getStairsPosition().y*24);
    sf::RenderWindow::draw(stairsS);
}

void SFMLCanvas::setMap(Map *map)
{
    this->map = map;
    level = map->getLevel();
}
