#include "QSFMLWidget.h"
#include <QDebug>

QSFMLWidget::QSFMLWidget(QWidget *parent) :
    QWidget(parent), m_initialized(false)
{
    qDebug() << Q_FUNC_INFO;

    // Произведём настройку для непосредственной отрисовки изображения в виджет
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    // Установим строгую фокусировку для включения событий клавиатуры
    setFocusPolicy(Qt::StrongFocus);
}

QPaintEngine* QSFMLWidget::paintEngine() const
{
//    qDebug() << Q_FUNC_INFO;

    // Возвращаем nullptr вместо движка отрисовки Qt, чтобы Qt не пытался что либо рисовать сам
    return nullptr;
}

void QSFMLWidget::showEvent(QShowEvent *event)
{
    qDebug() << Q_FUNC_INFO;

    // Первичная инициализация виджета SFML
    if ( m_initialized == false)
    {/*
#ifdef Q_WS_X11
        XFlush(QX11infod::display());
#endif*/

        // Создаём SFML окно для отрисовки с указанием Id окна, в котором будет производиться отрисовка
        sf::RenderWindow::create(reinterpret_cast<sf::WindowHandle>(winId()));
        // error above???
        setVerticalSyncEnabled(true);
        // Инициализация объектов отрисовки
        onInit();

        // Настройка таймера для перезапуска отрисовки виджета
        connect(&m_timer, SIGNAL(timeout()), this, SLOT(repaint()));
        m_timer.start();

        m_initialized = true;
    }

}

void QSFMLWidget::paintEvent(QPaintEvent *event)
{
//    qDebug() << Q_FUNC_INFO;

    sf::RenderWindow::clear();
    // Обновление отрисовки объектов
    onUpdate();

    // Отображение отрисованного окна
    sf::RenderWindow::display();
}

void QSFMLWidget::onInit()
{
    qDebug() << Q_FUNC_INFO;

    // To be overridden
}

void QSFMLWidget::onUpdate()
{
//    qDebug() << Q_FUNC_INFO;

    // To be overridden

}
