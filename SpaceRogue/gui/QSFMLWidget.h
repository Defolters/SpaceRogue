#ifndef QSFMLWIDGET_H
#define QSFMLWIDGET_H
/*
#ifdef Q_WS_X11
#include <Qt/qx11info_x11.h>
#include <X11\Xlib.h>
#endif*/

#include <QTimer>
#include <QObject>
#include <QWidget>
#include <SFML/Graphics.hpp>

class QSFMLWidget : public QWidget, public sf::RenderWindow
{
    Q_OBJECT

public:
    explicit QSFMLWidget(QWidget* parent = 0);
    // Метод, возвращающий движок отрисовки Qt
    virtual QPaintEngine* paintEngine() const;
    // Метод событий открытия и закрытия виджета, понадобится для первоначальной инициализации
    virtual void showEvent(QShowEvent *event);
    // Метод отрисовки, понадобится нам для перерисовки виджета
    virtual void paintEvent(QPaintEvent *event);

    // Метод первоначальной инициализации виджета
    virtual void onInit();
    // Метод обновления содержимого виджета
    virtual void onUpdate();

private:
    QTimer m_timer;
    bool   m_initialized;
};

#endif // QSFMLWIDGET_H
