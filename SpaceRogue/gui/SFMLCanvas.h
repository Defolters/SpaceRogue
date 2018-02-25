#ifndef SFMLCANVAS_H
#define SFMLCANVAS_H

#include "QSFMLWidget.h"

class SFMLCanvas : public QSFMLWidget
{

public:

    explicit SFMLCanvas(QWidget *parent = 0);

    void onInit() override;
    void onUpdate() override;

private:

    sf::Texture m_tex;
    sf::Sprite m_sprite;

};

#endif // SFMLCANVAS_H
