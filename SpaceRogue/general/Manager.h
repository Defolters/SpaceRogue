#ifndef MANAGER_H
#define MANAGER_H

/*! Класс manager, он следит за днями и предоставляет возможность выполнить какое-то действие за один ход.
 * Он получает список живых объектов, а затем предоставляет возможность походить сначала персонажу, затем остальным
*/
class Manager : public QObject
{
    Q_OBJECT

public:
    Manager();
    void start(bool always, int );
    void setMap(Map* map_);
    void setMainWindow(MainWindow* mw_);

signals:

private:
    int turn;
    MainWindow* mw;
    Map* map;
};

#endif // MANAGER_H
