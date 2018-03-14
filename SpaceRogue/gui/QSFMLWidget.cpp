#include "QSFMLWidget.h"
#include <QDebug>

QSFMLWidget::QSFMLWidget(QWidget *parent) :
    QWidget(parent), m_initialized(false)
{
    qDebug() << Q_FUNC_INFO;

    // ��������� ��������� ��� ���������������� ��������� ����������� � ������
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    // ��������� ������� ����������� ��� ��������� ������� ����������
    setFocusPolicy(Qt::StrongFocus);
}

QPaintEngine* QSFMLWidget::paintEngine() const
{
//    qDebug() << Q_FUNC_INFO;

    // ���������� nullptr ������ ������ ��������� Qt, ����� Qt �� ������� ��� ���� �������� ���
    return nullptr;
}

void QSFMLWidget::showEvent(QShowEvent *event)
{
    qDebug() << Q_FUNC_INFO;

    // ��������� ������������� ������� SFML
    if ( m_initialized == false)
    {/*
#ifdef Q_WS_X11
        XFlush(QX11infod::display());
#endif*/

        // ������ SFML ���� ��� ��������� � ��������� Id ����, � ������� ����� ������������� ���������
        sf::RenderWindow::create(reinterpret_cast<sf::WindowHandle>(winId()));
        // error above???
        setVerticalSyncEnabled(true);
        // ������������� �������� ���������
        onInit();

        // ��������� ������� ��� ����������� ��������� �������
        connect(&m_timer, SIGNAL(timeout()), this, SLOT(repaint()));
        m_timer.start();

        m_initialized = true;
    }

}

void QSFMLWidget::paintEvent(QPaintEvent *event)
{
//    qDebug() << Q_FUNC_INFO;

    sf::RenderWindow::clear();
    // ���������� ��������� ��������
    onUpdate();

    // ����������� ������������� ����
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
