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
    sf::Texture wallT;
    sf::Sprite floorS;
    sf::Sprite wallS;
    Map *map;
    int **level;

};

#endif // SFMLCANVAS_H
