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

private:

    sf::Texture m_tex;
    sf::Sprite m_sprite;
    // ADDITIONAL FIELDS FOR SPACEROGUE
    sf::Texture floorT;
    sf::Texture floor1T;
    sf::Texture floor2T;
    sf::Texture wallT;
    sf::Sprite floorS;
    sf::Sprite floor1S;
    sf::Sprite floor2S;
    sf::Sprite wallS;
    sf::Texture playerT;
    sf::Sprite playerS;
    sf::Texture startT;
    sf::Sprite startS;
    Map *map;
    int **level;

};

#endif // SFMLCANVAS_H
