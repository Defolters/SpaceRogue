#include "SFMLCanvas.h"
#include <iostream>
#include <QDebug>
#include <QKeyEvent>

SFMLCanvas::SFMLCanvas(QWidget *parent) :
    QSFMLWidget(parent), map(nullptr), gameOver(false)
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
    if (!enemyT.loadFromFile("enemy.png"))
    {
        std::cout << "Failed to find texture" << std::endl;
        return;
    }
    if (!bloodT.loadFromFile("blood.png"))
    {
        std::cout << "Failed to find texture" << std::endl;
        return;
    }
    if (!gameOverT.loadFromFile("gameOver.png"))
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
    enemyS.setTexture(enemyT);
    bloodS.setTexture(bloodT);
    gameOverS.setTexture(gameOverT);
}

void SFMLCanvas::onUpdate()
{
    if (gameOver)
    {
        sf::RenderWindow::clear();
        bloodS.setPosition(0,70);
        sf::RenderWindow::draw(bloodS);
        gameOverS.setPosition(300,160);
        sf::RenderWindow::draw(gameOverS);
        return;
    }
    // draw level
    int **vision = map->getVision();
    for (int i = 0; i < map->getWidth(); i++)
    {
        for (int j = 0; j < map->getHeight(); j++)
        {
            if ((vision[i][j] != 5) && (vision[i][j] != 6)) {continue;}
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

    // draw start point
    if (vision[(int)map->getPlayerStartPosition().x][(int)map->getPlayerStartPosition().y] == 5)
    {
        startS.setPosition(map->getPlayerStartPosition().x*24, map->getPlayerStartPosition().y*24);
        sf::RenderWindow::draw(startS);
    }

    // draw player
    playerS.setPosition(map->getPlayer()->getPosition().x*24,map->getPlayer()->getPosition().y*24);
    sf::RenderWindow::draw(playerS);

    // draw stairs
    if (vision[(int)map->getStairsPosition().x][(int)map->getStairsPosition().y] == 5)
    {
        stairsS.setPosition(map->getStairsPosition().x*24, map->getStairsPosition().y*24);
        sf::RenderWindow::draw(stairsS);
    }

    // draw enemies
    for (auto alive : map->getAlive())
    {
        if (vision[(int)alive->getPosition().x][(int)alive->getPosition().y] == 5)
        {
            enemyS.setPosition(alive->getPosition().x*24, alive->getPosition().y*24);
            sf::RenderWindow::draw(enemyS);
        }
    }
}

void SFMLCanvas::setMap(Map *map)
{
    this->map = map;
    level = map->getLevel();
}

void SFMLCanvas::endOfGame()
{
    gameOver=true;
}
