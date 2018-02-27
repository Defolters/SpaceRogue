#ifndef DUNGEON_GENERATION
#define DUNGEON_GENERATION

#include <array>
#include <iostream>
#include <vector>
#include <random>

/** Dungeon Generation
 * My own implementation of some algorithms for dungeon generation
 * @author defolter
 * @version 0.1
*/

//! namespace
namespace DunGen {

/**
 * @brief The Room == Rectangle
 */
class Room
{

public:
    Room(int x,int y,int w,int h) : x1(x), x2(x+w), y1(y), y2(y+h) {}

    //! Method returns array with center of @class Room
    int* center()
    {
        int* cent = new int[2];
        cent[0] = (int)(x1+x2)/2;
        cent[1] = (int)(y1+y2)/2;
        return cent;
    }

    bool intersect(Room *other)
    {
        return ((x1 <= other->x2) & (x2 >= other->x1) & (y1 <= other->y2) & (y2 >= other->y1));
    }

    int x1;  //!< left
    int x2;  //!< right
    int y1;  //!< up
    int y2;  //!< down
};

/**
 * @brief The TunnelingAlg class
 * 1 - wall
 * 0 - can move;
 */
class TunnelingAlg
{

public:
    TunnelingAlg(int maxRooms, int minRoomSize, int maxRoomSize) :
        maxRooms(maxRooms), minRoomSize(minRoomSize), maxRoomSize(maxRoomSize),
        level(nullptr), mt(rd()) {}

    ~TunnelingAlg() {} // should I delete array?

    int** generateLevel(int levelWidth, int levelHeight, int maxRooms,
                        int minRoomSize, int maxRoomSize)
    {
        this->maxRooms = maxRooms;
        this->minRoomSize = minRoomSize;
        this->maxRoomSize = maxRoomSize;
        this->levelWidth = levelWidth;
        this->levelHeight = levelHeight;

        // Create 2d array
        this->level = new int*[levelWidth];
        for(int i = 0; i < levelWidth; ++i)
            this->level[i] = new int[levelHeight];

        // Fill 2d array
        for(int i=0;i<levelWidth;i++)
        {
            for(int j=0;j<levelHeight;j++)
            {
                this->level[i][j] = 1;
            }
        }

        //
        std::vector<Room*> rooms; // I should also return this for our tasks
        int numRooms = 0;

        for(int r = 0; r < this->maxRooms; r++)
        {
            // random width and height
            std::uniform_int_distribution<int> distMinMax(this->minRoomSize, this->maxRoomSize);
            int w = distMinMax(mt);
            int h = distMinMax(mt);
            //std::cout << w << " */\*" << h << std::endl;
            //random position within map boundries
            std::uniform_int_distribution<int> distx(0, this->levelWidth-w-1);
            int x = distx(mt);
            std::uniform_int_distribution<int> disty(0, this->levelHeight-h-1);
            int y = disty(mt);
            //std::cout << x << " */-\*" << y << std::endl;

            Room *newRoom = new Room(x, y, w, h);
            //check for overlap with previous rooms
            bool failed = false;

            //for
            for(auto room : rooms)
            {
                if (newRoom->intersect(room))
                {
                    failed = true;
                    break;
                }
            }

            //if not
            if (!failed)
            {
                this->createRoom(newRoom);
                int *cent = newRoom->center();

                if (numRooms != 0)
                {
                    // all rooms after the first one
                    // connect to the previous room

                    // center coordinates of the previous room
                    int *prevCent = rooms.back()->center();

                    // 50% chance that a tunnel will start horizontally
                    std::uniform_int_distribution<int> dist(0, 1);
                    if (dist(mt) == 1)
                    {
                        createHorTunnel(prevCent[0], cent[0], prevCent[1]);
                        createVirTunnel(prevCent[1], cent[1], cent[0]);
                    }
                    else
                    {
                        createVirTunnel(prevCent[1], cent[1], cent[0]);
                        createHorTunnel(prevCent[0], cent[0], prevCent[1]);
                    }
                }

                rooms.push_back(newRoom);
                numRooms++;
            }

        }

        return this->level;
    }

    void createRoom(Room *room)
    {
        for(int x = room->x1+1; x < room->x2; x++)
        {
            for(int y = room->y1+1; y < room->y2; y++)
            {
                this->level[x][y] = 0;
            }
        }
    }

    void createHorTunnel(int x1, int x2, int y)
    {
        for (int x = std::min(x1,x2); x < (std::max(x1,x2)+1); x++)
        {
            this->level[x][y] = 0;
        }
    }

    void createVirTunnel(int y1, int y2, int x)
    {
        for (int y = std::min(y1,y2); y < (std::max(y1,y2)+1); y++)
        {
            this->level[x][y] = 0;
        }
    }

private:
    int maxRooms;
    int maxRoomSize;
    int minRoomSize;
    int levelWidth;
    int levelHeight;
    int **level;
    std::random_device rd;
    std::mt19937 mt;
};

/**
 * @brief The Map class
 */
class Map
{

public:
    Map(int width, int height) : level(nullptr), width(width), height(height),
        tunAlg(new TunnelingAlg(0,0,0)) {}

    //! Should I delete level??
    ~Map()
    {
        /*for (int i = 0; i < width; i++)
        {
            delete[] level[i];
        }
        delete[] level;*/
    }

    //! Method creates empty level
    void createLevel(const int width, const int height)
    {
        this->width = width;
        this->height = height;

        this->level = new int*[width];

        for(int i = 0; i < width; ++i)
            this->level[i] = new int[height];

        for(int i=0;i<width;i++)
            for(int j=0;j<height;j++)
            {
                this->level[i][j] = 0;
            }
    }

    int** generateLevel(int maxRooms, int minRoomSize, int maxRoomSize)
    {
        this->level = tunAlg->generateLevel(width, height, maxRooms, minRoomSize, maxRoomSize);

        return this->level;
    }

    int getWidth() {return width;}

    int getHeight() {return height;}

    void printLevel()
    {
        for(int i=0;i<width;i++)
        {
            for(int j=0;j<height;j++)
            {
                if (this->level[i][j] == 1)
                    std::cout << "# ";
                if (this->level[i][j] == 0)
                    std::cout << ". ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

private:
    int **level;
    int width;
    int height;
    TunnelingAlg *tunAlg;
};

} // namespace DunGen

#endif // DUNGEON_GENERATION
