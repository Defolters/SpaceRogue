#ifndef COORDINATES_H
#define COORDINATES_H
#include <string>
#include "Headers.h"
//! Координаты в трехмерной плоскости
struct Coordinates
{
    Coordinates() : x(0), y(0), z(0) {};
    Coordinates(int x, int y, int z) : x(x), y(y), z(z) {};

    double x;
    double y;
    double z;

	std::string toString() 
	{ 
		std::string res;
		res += std::to_string(x);
		res += " ";
		res += std::to_string(y);
		res += " ";
		res += std::to_string(z);
		return res;
	}
    Vector2f toVector2f() { return Vector2f((float)x, (float)y); }
    
    double getDistance(Coordinates coord) 
    {
        double distance = sqrt(pow(this->x - coord.x, 2) + pow(this->y - coord.y, 2) + pow(this->z - coord.z, 2));
        return distance;
    }

    bool operator==(const Coordinates& coord)
    {
        if (this == &coord)
        {
            return true;
        }
        if ((this->x == coord.x) && (this->y == coord.y) && (this->z == coord.z))
        {
            return true;
        }
        else
        {
            return false;
        }

    }
};
#endif //! COORDINATES_H