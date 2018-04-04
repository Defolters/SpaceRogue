#ifndef MAP_H
#define MAP_H

#include <memory>
#include <random>
#include <list>
#include <QObject>

#include "DungeonGeneration.hpp"
#include "FoV.hpp"
#include "../player/Player.h"
#include "../player/MovePlanner.h"
#include "../enemies/Enemy.h"


//#include "../enemies/Enemy.h"

//! Класс, который содержит карту местности. В папке field так же могут быть служебные классы для генерации карты и проч..
// Что у нас будет местностью? Космический корабль/станция?
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

    //! Выбор сложности. Влияет на количество мностров и предметов.
    //! Можно выбрать из главного меню, тогда карта должна перегенерироваться?
    void setDifficulty(int difficulty);

    //! Method sets main player
    // Или аргумент shared_ptr?
    //void setPlayer(Player* player);
    void setPlayer(Player* player);

    //! Method returns player
    Player* getPlayer();

    //! Method generates level with MapCreator and then places different objects
    void generateLevel();

    //! Method returns width of the map
    int getWidth();

    //! Method returns height of the map
    int getHeight();

    //! Methods returns list with alive objects
    std::list<Alive*> &getAlive();

    //! Method returns level
    int** getLevel();
    int **getVision();

    //! Method
    void movePlayer(int key); // reformat this

    //! Method move creature to newPosition, if it is possible
    void moveCreature(Alive* creature, Vector2f newPosition);

    //! Method moves enemies
    void moveEnemies();

    //! Method returns player's spawn position
    Vector2f getPlayerStartPosition();

    //! Method returns position of stairs
    Vector2f getStairsPosition();

    //! Method returns the current number of level
    int getLevelNumber();

    //!
    bool isSomebodyHere(Vector2f pos, Alive *creature);

    // TEST
    void makeTurn();
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
    //! Method adds a bit of traps in random places in rooms
    void placeTraps();

    //!
    //! \brief mapCreator
    //!
    FOV* fov;
    DunGen::Map *mapCreator;
    //! data structure that contains map (4 width, 3 height)
    int **level;
    int **vision;
    //! Vector with rooms placed on level
    std::vector<DunGen::Room*> rooms;
    //! List with all objects
    //std::list<std::shared_ptr<Object>> objects;
    //! List with alive objects
    std::list<Alive*> alive;
    //! Position where player is spawned
    sf::Vector2f playerStartPosition;
    //! Position of stairs to next level
    sf::Vector2f stairsPosition;
    //!
    //! Vector of traps
    std::vector<Vector2f> traps;
    //!
    int turn;
    int difficulty;
    int levelNumber;
    Player* player;
    MovePlanner *movePlanner;
    std::random_device rd;
    std::mt19937 mt;

};

#endif // MAP_H
