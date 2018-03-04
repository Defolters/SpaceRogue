#include "Map.h"
#include <QDebug>


Map::Map(int difficulty) :
    mapCreator(new DunGen::Map(MAP_WIDTH,MAP_HEIGHT)),
    movePlanner(new MovePlanner()),
    difficulty(difficulty), levelNumber(0), turn(0), mt(rd())
{
//    generateLevel();
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
    //add plyaer to list
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
    movePlanner->setAlive(alive);
    // select random rooms and create enemies (depends on difficulty, cannot be in one room with player??)

    // select random rooms and create items (depends on difficulty)

    // add alive to move planner
    // start move planner if game plays itself
    // else move planner work when player do actions (movements)
    // move planner analyze state of Alive creature and do some movement (action)
    difficulty++;
    levelNumber++;
}

int Map::getWidth()
{
    return MAP_WIDTH;
}

int Map::getHeight()
{
    return MAP_HEIGHT;
}

std::list<std::shared_ptr<Alive> > &Map::getAlive()
{
    return alive;
}

int **Map::getLevel()
{
    return level;
}

void Map::movePlayer(int key) // move every creature
{
    QString message;
    if (key == 16777236)
    {
//        key = "Right";
        if (level[(int)player->getPosition().x+1][(int)player->getPosition().y] != 1)
        {
            Vector2f pos = Vector2f(player->getPosition().x+1, player->getPosition().y);
            if (!isSomebodyHere(pos))
                player->setPosition(pos);

        }else {message="Sorry, you cannot move through walls";}
    }
    else if (key == 16777234)
    {
//        key = "Left";
        if (level[(int)player->getPosition().x-1][(int)player->getPosition().y] != 1)
        {
            Vector2f pos = Vector2f(player->getPosition().x-1, player->getPosition().y);
            if (!isSomebodyHere(pos))
                player->setPosition(pos);

        }else {message="Sorry, you cannot move through walls";}

    }
    else if (key == 16777235)
    {
//        key = "Up";
        if (level[(int)player->getPosition().x][(int)player->getPosition().y-1] != 1)
        {
            Vector2f pos = Vector2f(player->getPosition().x, player->getPosition().y-1);
            if (!isSomebodyHere(pos))
                player->setPosition(pos);

        }else {message="Sorry, you cannot move through walls";}\
    }
    else if (key == 16777237)
    {
//        key = "Down";
        if (level[(int)player->getPosition().x][(int)player->getPosition().y+1] != 1)
        {
            Vector2f pos = Vector2f(player->getPosition().x, player->getPosition().y+1);
            if (!isSomebodyHere(pos))
                player->setPosition(pos);

        }else {message="Sorry, you cannot move through walls";}

    }

    if (!message.isEmpty())
    {
        emit newEvent(message);
    }
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
            emit newEvent(QString("Player got in hidden trap"));
        }
    }

    if (player->isDead())
    {
        // stop game and suggest to start again
    }
    turn++;
    emit newTurn(turn);
    // every seven turn heal us
    if (turn % 7 == 0)
    {
        player->addHealth(1);
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
    movePlanner->makeTurn();
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
    for (auto creature : alive)
    {
        if ((creature->getPosition().x == pos.x) && (creature->getPosition().y == pos.y))
        {
            creature->reduceHealth(player->getStrength());
            emit newEvent(QString("You hit " + creature->getName() + " his health: " + QString::number(creature->getHealth())));
            return true;
        }
    }
    return false;
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
    alive.cbegin();
    for (int i=1;i<3;i++)
    {
        // create enemy
        std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>(QString("Enemy"), 2, 0, 1);
        // set position
        enemy->setPosition(Vector2f(rooms.at(i)->center()[0], rooms.at(i)->center()[1]));
        // put into list
        alive.push_back(std::static_pointer_cast<Alive>(enemy));
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
