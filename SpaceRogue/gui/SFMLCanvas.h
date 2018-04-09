#ifndef SFMLCANVAS_H
#define SFMLCANVAS_H

#include "QSFMLWidget.h"
#include "../field/Map.h"

class SFMLCanvas : public QSFMLWidget
{

public:

    explicit SFMLCanvas(QWidget *parent = 0);

    virtual void keyPressEvent(QKeyEvent* event);
    // first initialization of sfml window
    void onInit() override;
    // update view of window
    void onUpdate() override;

    // ADDITIONAL METHODS FOR SPACEROGUE
    void setMap(Map *map);

    void endOfGame();

private:
    sf::Texture floorT;
    sf::Texture floor1T;
    sf::Texture floor2T;

    sf::Sprite floorS;
    sf::Sprite floor1S;
    sf::Sprite floor2S;

    sf::Texture wallT;
    sf::Sprite wallS;

    sf::Texture playerT;
    sf::Sprite playerS;

    sf::Texture startT;
    sf::Sprite startS;

    sf::Texture stairsT;
    sf::Sprite stairsS;

    sf::Texture enemyT;
    sf::Sprite enemyS;

    sf::Texture bloodT;
    sf::Sprite bloodS;

    sf::Texture gameOverT;
    sf::Sprite gameOverS;
    bool gameOver;
    Map *map;
    int **level;

};

#endif // SFMLCANVAS_H
