#ifndef PLAYER_H
#define PLAYER_H

/*! Класс player
 *
*/
class Player
        : public Alive
{
public:
    Player();
private:
    MovePlanner* movePlanner;
};

#endif // PLAYER_H
