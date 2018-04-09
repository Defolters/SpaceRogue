#include "Map.h"
#include <QDebug>
#include <chrono>


Map::Map(int difficulty) :
    mapCreator(new DunGen::Map(MAP_WIDTH,MAP_HEIGHT)),
    movePlanner(new MovePlanner()),
    difficulty(difficulty), levelNumber(0), turn(0), mt(rd()), fov(new FOV)
{
    player = new Player("Player One");
}


Map::~Map()
{
}

void Map::run()
{
    std::chrono::time_point<std::chrono::system_clock> start, start2, end1, end2;
        start = std::chrono::system_clock::now();
        while (1)
        {
            end1 = std::chrono::system_clock::now();
            if((std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start) > std::chrono::milliseconds(250)))
            {
                start = std::chrono::system_clock::now();
                makeTurn();
            }
        }
}

void Map::setDifficulty(int difficulty)
{
    this->difficulty = difficulty;
}

void Map::setPlayer(Player *player)
{
    //add player to list
    this->player = player;
}

Player *Map::getPlayer()
{
    return player;
}

void Map::generateLevel()
{
    //create level
    level = mapCreator->generateLevel(100,3,10);

    rooms = mapCreator->getRooms();
    unvisited = QList<DunGen::Room*>::fromVector(QVector<DunGen::Room*> ::fromStdVector(mapCreator->getRooms()));

    // select random room for init of player
    placePlayer();
    placeStairs();
    placeTraps();
    placeEnemies();
    //placeItems();
    // add to player coordinates of generation
    player->setPosition(playerStartPosition);
    vision = fov->getVision(level, MAP_WIDTH, MAP_HEIGHT, 90, (int)player->getPosition().x, (int)player->getPosition().y);
    movePlanner->setAlive(alive);
    // select random rooms and create enemies (depends on difficulty, cannot be in one room with player??)

    // select random rooms and create items (depends on difficulty)

    // add alive to move planner
    // start move planner if game plays itself
    // else move planner work when player do actions (movements)
    // move planner analyze state of Alive creature and do some movement (action)
    difficulty++;
    levelNumber++;

    emit newTurn(turn);
}

int Map::getWidth()
{
    return MAP_WIDTH;
}

int Map::getHeight()
{
    return MAP_HEIGHT;
}

std::list<Alive *> &Map::getAlive()
{
    return alive;
}

int **Map::getLevel()
{
    return level;
}

int **Map::getVision()
{
    return vision;
}

DunGen::Room *Map::getNearestRoom(QList<DunGen::Room*> rooms, Vector2f pos)
{
    // перебрать комнаты и найти то, путь к которой занимает наименьшее количество движений
    if (rooms.size() == 0)
        return nullptr;

    DunGen::Room *room = rooms.at(0);
    int minDistance = getDistance(Vector2f(room->center()[0], room->center()[1]), pos);

    for (int i=0;i<rooms.size();i++)
    {
        int distance = getDistance(Vector2f(rooms.at(i)->center()[0], rooms.at(i)->center()[1]), pos);

        if (distance < minDistance)
        {
            room = rooms.at(i);
        }
    }
    return room;
}

int Map::getDistance(Vector2f first, Vector2f second)
{
    QList<Way> path;
    path = movePlanner->findWay(first, second, level, MAP_WIDTH, MAP_HEIGHT);

    return path.size();
    //return sqrt(pow((firsts.x-second.x),2 ) + pow((first.y-second.y),2 ) );
}

void Map::movePlayer(int key) // move every creature
{
    Vector2f newPosition;

    if (key == 16777236)
    {
//        key = "Right";
        newPosition.x = 1;
        newPosition.y = 0;
    }
    else if (key == 16777234)
    {
//        key = "Left";
        newPosition.x = -1;
        newPosition.y = 0;
        qDebug() << "Left";
    }
    else if (key == 16777235)
    {
//        key = "Up";
        newPosition.x = 0;
        newPosition.y = -1;
    }
    else if (key == 16777237)
    {
//        key = "Down";
        newPosition.x = 0;
        newPosition.y = 1;
    }

    moveCreature(player, newPosition);
//    moveEnemies();
    makeTurn();
}

void Map::movePlayer()
{
    // check if player see stairs
//    if it's true, set aim = stairs and move

    QList<Way> path;
    path = movePlanner->findWay(player->getPosition(),
                                player->getAim(stairsPosition), level,
                                MAP_WIDTH, MAP_HEIGHT);

    if (path.size() != 0)
    {
        Way top = path.at(0);
        Vector2f newPosition;

        if (top == Way::RIGHT)
        {
    //        key = "Right";
            newPosition.x = 1;
            newPosition.y = 0;
        }
        else if (top == Way::LEFT)
        {
    //        key = "Left";
            newPosition.x = -1;
            newPosition.y = 0;
        }
        else if (top == Way::UP)
        {
    //        key = "Up";
            newPosition.x = 0;
            newPosition.y = -1;
        }
        else if (top == Way::DOWN)
        {
    //        key = "Down";
            newPosition.x = 0;
            newPosition.y = 1;
        }

    // move enemies to coordinates
        moveCreature(player, newPosition);
    }
}

void Map::findPlayerAim()
{
    // если видим спуск, то движемся toward it
    if (vision[(int)stairsPosition.x][(int)stairsPosition.y] == 5)
    {
        player->setAim(stairsPosition);
        return;
    }

    // если видим предмет, то его нужно захватить



    // иначе движемся в ближайшую комнату
    DunGen::Room *room;
    room = getNearestRoom(unvisited, player->getPosition());

    // список посещенных
    Vector2f p = player->getPosition();
    QMutableListIterator<DunGen::Room*> iter(unvisited);
    while(iter.hasNext())
    {
        DunGen::Room *roomIn;
        roomIn = iter.next();

        if (((p.x > roomIn->x1)&&(p.x < roomIn->x2)) &&
                ((p.y > roomIn->y1)&&(p.y < roomIn->y2)))
        {
            iter.remove();
            break;
        }
        // если находимся в комнате, то удаляем ее и перемещаем в
    }
    // если мы находимся в комнате, то эту комнату переместить в посещенные? или просто удалить
    // список непосещенных

    player->setAim(Vector2f(room->center()[0], room->center()[1]));
}

void Map::moveCreature(Alive *creature, Vector2f newPosition)
{
    // ENEMIES AND TRAPS!! (NULLPTR??)
    bool isMoved = false;
    QString message;
    if (level[(int)(creature->getPosition().x+newPosition.x)][(int)(creature->getPosition().y+newPosition.y)] != 1)
    {
        Vector2f pos = Vector2f(creature->getPosition().x+newPosition.x, creature->getPosition().y+newPosition.y);
        if (creature->getName() == QString("Player One"))
        {
            if (!isSomebodyHere(pos))
                creature->setPosition(pos);
            isMoved = true;
        }
        else
        {
            if (!isPlayerNear(creature))
                creature->setPosition(pos);
            isMoved = true;
        }

    }
    else {emit newEvent(QString("Sorry, you cannot move through walls"));}

    if (!isMoved)
        return;

    if (!message.isEmpty())
    {
        emit newEvent(message);
    }

    // player instead of creature, because creatures don't use stairs
    if (player->getPosition() == stairsPosition)
    {
        emit newLevel();
        emit newEvent(QString("Player get to the next level"));
    }

    for (auto pos : traps)
    {
        if ((pos.x == player->getPosition().x) && (pos.y == player->getPosition().y))
        {
            player->reduceHealth(2);
            emit newEvent(QString("%1 got in hidden trap").arg(player->getName()));
        }
    }

    if (player->isDead())
    {
        // stop game and suggest to start again
        emit gameOver();
        return;
    }
    if (creature->getName() == QString("Player One"))
    {
        turn++;
        emit newTurn(turn);
        // every seven turn heal us
        if (turn % 7 == 0)
        {
            player->addHealth(1);
        }
    }
    // add health
    // if at trap minus health

    // check that creatures is alive (i can kill them)
    auto iter = alive.begin();
    while(iter!=alive.end())
    {
        if((*iter)->isDead())
        {
            //delete
            alive.erase(iter++);
        }
        else
        {
            ++iter;
        }
    }
    // AFTER THIS ALLOW MOVEPLANNER TO MAKE TURN
//    movePlanner->makeTurn();
    //FOV::getVision(level, MAP_WIDTH, MAP_HEIGHT, 10, (int)player->getPosition().x, (int)player->getPosition().y);
    if (creature->getName() == QString("Player One"))
    {
        vision = fov->getVision(level, MAP_WIDTH, MAP_HEIGHT, 10,
                                (int)player->getPosition().x,
                                (int)player->getPosition().y);
    }
}

void Map::moveEnemies()
{
    // check if enemies see or saw player (aim position updating )
    // find path
    // adopt path to coordinates
    // move enemies to coordinates
    for (auto creature : alive)
    {
        // check if enemies see or saw player (aim position updating )
        Vector2f aim = creature->getAim(player->getPosition());

        // find path
        QList<Way> path;
        path = movePlanner->findWay(creature->getPosition(), aim, level, MAP_WIDTH, MAP_HEIGHT);
        for (auto top : path)
        {
            if (top == Way::RIGHT)
            {
                qDebug() << "Right";
            }
            else if (top == Way::LEFT)
            {
        qDebug() << "Left";
            }
            else if (top == Way::UP)
            {
        qDebug() << "Up";
            }
            else if (top == Way::DOWN)
            {
        qDebug() << "Down";
            }
        }
        // adopt path to coordinates
        if (path.size() != 0)
        {
            Way top = path.at(0);
            Vector2f newPosition;

            if (top == Way::RIGHT)
            {
        //        key = "Right";
                newPosition.x = 1;
                newPosition.y = 0;
            }
            else if (top == Way::LEFT)
            {
        //        key = "Left";
                newPosition.x = -1;
                newPosition.y = 0;
            }
            else if (top == Way::UP)
            {
        //        key = "Up";
                newPosition.x = 0;
                newPosition.y = -1;
            }
            else if (top == Way::DOWN)
            {
        //        key = "Down";
                newPosition.x = 0;
                newPosition.y = 1;
            }

        // move enemies to coordinates
            moveCreature(creature, newPosition);
        }
    }
}

Vector2f Map::getPlayerStartPosition()
{
    return playerStartPosition;
}

Vector2f Map::getStairsPosition()
{
    return stairsPosition;
}

int Map::getLevelNumber()
{
    return levelNumber;
}

bool Map::isSomebodyHere(Vector2f pos)
{
    // if player, we should move to enemy to damage
    for (auto creat : alive)
    {
        if ((creat->getPosition().x == pos.x) && (creat->getPosition().y == pos.y))
        {
            creat->reduceHealth(player->getStrength());
            emit newEvent(QString("You hit " + creat->getName() + " his health: " + QString::number(creat->getHealth())));
            return true;
        }
    }


    return false;
}

bool Map::isPlayerNear(Alive *creature)
{
    // else we should stay near
    if (sqrt( pow((creature->getPosition().x-player->getPosition().x),2) + pow((creature->getPosition().y-player->getPosition().y),2)) < 2)
    {
        player->reduceHealth(creature->getStrength());
        emit newEvent(QString("You hit " + player->getName() + " his health: " + QString::number(player->getHealth())));
        return true;
    }

    return false;
}

void Map::makeTurn()
{
    // move player
    findPlayerAim();
    movePlayer();

    // move enemies
    moveEnemies();
}

void Map::placePlayer()
{
    // create player..
    playerStartPosition = Vector2f(rooms.front()->center()[0], rooms.front()->center()[1]);
}

void Map::placeStairs()
{
    stairsPosition = Vector2f(rooms.back()->center()[0], rooms.back()->center()[1]);
}

void Map::placeEnemies()
{
    // а если комнат меньше десяти???
    alive.clear();
    for (int i=1;i<10;i++)
    {
        if (i>rooms.size())
            break;

        // create enemy
        Enemy* enemy = new Enemy(QString("Enemy"),1 , 0, 2);
        // set position
        enemy->setPosition(Vector2f(rooms.at(i)->center()[0], rooms.at(i)->center()[1]));
        // put into list
        alive.push_back(enemy);
    }
}

void Map::placeTraps()
{
    std::uniform_int_distribution<int> distRoom(0, rooms.size()-1);
    int chance;
    for (int i =0;i<2;i++)
    {
        chance = distRoom(mt);
        DunGen::Room *room = rooms.at(chance);
        std::uniform_int_distribution<int> distX(room->x1, room->x2);
        std::uniform_int_distribution<int> distY(room->y1, room->y2);
        Vector2f placeForTrap = Vector2f(distX(mt),distY(mt));
        traps.push_back(placeForTrap);
        qDebug() << placeForTrap.x << "_" << placeForTrap.y;
    }

    // случайные комнаты, случайные места, поставить ловушки
}
