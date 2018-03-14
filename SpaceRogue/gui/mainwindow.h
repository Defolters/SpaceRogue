#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>
#include <QMainWindow>
#include "../field/Map.h"
#include "../general/Manager.h"
#include "../player/Player.h"

namespace Ui {
class MainWindow;
}
/*! Основа программы:
 * содержит в себе главные компоненты
 * запускает всю работу и следит за состоянием, чтобы все это выводить.
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    //!
    bool eventFilter(QObject *obj, QEvent *event);


private slots:
    //!
    void on_generateLevel_clicked();
    //! Method adds message to log tab
    void addLogMessage(const QString &text);
    void newLevel();
    void newTurn(int turn);
private:


    Map* map;  //!< map contains level
    Manager* manager;  //!< manager


    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
