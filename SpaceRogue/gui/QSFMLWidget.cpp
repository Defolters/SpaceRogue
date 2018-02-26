#include "QSFMLWidget.h"

QSFMLWidget::QSFMLWidget(QWidget *parent) :
    QWidget(parent), m_initialized(false)
{
    // ��������� ��������� ��� ���������������� ��������� ����������� � ������
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    // ��������� ������� ����������� ��� ��������� ������� ����������
    setFocusPolicy(Qt::StrongFocus);
}

QPaintEngine* QSFMLWidget::paintEngine() const
{
    // ���������� nullptr ������ ������ ��������� Qt, ����� Qt �� ������� ��� ���� �������� ���
    return nullptr;
}

void QSFMLWidget::showEvent(QShowEvent *event)
{
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
    sf::RenderWindow::clear();
    // ���������� ��������� ��������
    onUpdate();

    // ����������� ������������� ����
    sf::RenderWindow::display();
}

void QSFMLWidget::onInit()
{
    // To be overridden
}

void QSFMLWidget::onUpdate()
{
    // To be overridden
}
