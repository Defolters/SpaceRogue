#include "Map.h"
#include <QDebug>


Map::Map(int difficulty) :
    mapCreator(new DunGen::Map(MAP_WIDTH,MAP_HEIGHT)),
    movePlanner(new MovePlanner()),
    difficulty(difficulty), levelNumber(0), turn(0), mt(rd()), fov(new FOV)
{
//    generateLevel();
    player = new Player("Player One");
}


Map::~Map()
{
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

void Map::moveCreature(Alive *creature, Vector2f newPosition)
{
    bool isMoved = false;
    QString message;
    if (level[(int)(creature->getPosition().x+newPosition.x)][(int)(creature->getPosition().y+newPosition.y)] != 1)
    {
        Vector2f pos = Vector2f(creature->getPosition().x+newPosition.x, creature->getPosition().y+newPosition.y);
        if (!isSomebodyHere(pos, creature))
            creature->setPosition(pos);
        isMoved = true;

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
        if ((pos.x == creature->getPosition().x) && (pos.y == creature->getPosition().y))
        {
            creature->reduceHealth(2);
            emit newEvent(QString("%1 got in hidden trap").arg(creature->getName()));
        }
    }

    if (player->isDead())
    {
        // stop game and suggest to start again
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

bool Map::isSomebodyHere(Vector2f pos, Alive *creature)
{
    if (creature->getName() == QString("Player One"))
    {
        for (auto creat : alive)
        {
            if ((creat->getPosition().x == pos.x) && (creat->getPosition().y == pos.y))
            {
                creat->reduceHealth(player->getStrength());
                emit newEvent(QString("You hit " + creat->getName() + " his health: " + QString::number(creat->getHealth())));
                return true;
            }
        }
    }
    else
    {
        if ((player->getPosition().x == pos.x) && (player->getPosition().y == pos.y))
        {
            player->reduceHealth(creature->getStrength());
            emit newEvent(QString("You hit " + player->getName() + " his health: " + QString::number(player->getHealth())));
            return true;
        }
    }

    return false;
}

void Map::makeTurn()
{
    for (auto creature : alive)
    {
        // check if enemies see or saw player (aim position updating )
        Vector2f aim = creature->getAim(player->getPosition());

        // find path
        QList<Way> path;
        path = movePlanner->findWay(creature->getPosition(), aim, level, MAP_HEIGHT, MAP_WIDTH);
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
    alive.clear();
    for (int i=1;i<2;i++)
    {
        // create enemy
        Enemy* enemy = new Enemy(QString("Enemy"), 2, 0, 1);
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
