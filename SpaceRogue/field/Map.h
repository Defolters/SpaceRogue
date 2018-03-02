#ifndef MAP_H
#define MAP_H

#include <memory>
#include <list>
#include <QObject>

#include "DungeonGeneration.hpp"
#include "../player/Player.h"
#include "../general/Alive.h"

//#include "../enemies/Enemy.h"

//! �����, ������� �������� ����� ���������. � ����� field ��� �� ����� ���� ��������� ������ ��� ��������� ����� � ����..
// ��� � ��� ����� ����������? ����������� �������/�������?
static const int MAP_WIDTH = 40;
static const int MAP_HEIGHT = 33;

/**
 * @brief The Map class
 * Size of level is constant
 */
class Map : public QObject
{
    Q_OBJECT

public:
    Map(int difficulty);
    ~Map();

    //! ����� ���������. ������ �� ���������� �������� � ���������.
    //! ����� ������� �� �������� ����, ����� ����� ������ ������������������?
    void setDifficulty(int difficulty);

    // ��� �������� shared_ptr?
    void setPlayer(Player* player);
    Player *getPlayer();
    void generateLevel();

    int getWidth();

    int getHeight();

    int** getLevel();

    void movePlayer(int key);
    Vector2f getPlayerStartPosition();
    Vector2f getStairsPosition();
    int getLevelNumber();
signals:
    //!
    void newEvent(const QString &text);
    //! Signal is emitted when we move to next level
    void newLevel();
    //!
    void newTurn(int turn);

private:
    //!
    void placePlayer();
    //!
    void placeStairs();
    //!
    void placeEnemies();
    //!
    void placeItems();
    void placeTraps();

    //!
    DunGen::Map *mapCreator;
    //! data structure that contains map (4 width, 3 height)
    int **level;
    //!
    std::vector<DunGen::Room*> rooms;
    //! data with all objects
    std::list<std::shared_ptr<Object>> objects;
    //! data with alive objects
    std::list<std::shared_ptr<Alive>> alive;
    //!
    sf::Vector2f playerStartPosition;
    sf::Vector2f stairsPosition;
    //!
    //!
    //!
    int turn;
    int difficulty;
    int levelNumber;
    Player* player;
};

#endif // MAP_H
