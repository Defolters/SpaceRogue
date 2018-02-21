#ifndef MANAGER_H
#define MANAGER_H

/*! ����� manager, �� ������ �� ����� � ������������� ����������� ��������� �����-�� �������� �� ���� ���.
 * �� �������� ������ ����� ��������, � ����� ������������� ����������� �������� ������� ���������, ����� ���������
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
