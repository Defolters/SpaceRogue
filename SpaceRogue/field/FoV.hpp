#ifndef FOV_HPP
#define FOV_HPP

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <QDebug>
class FOV {
public:
/*
int myMap[20][20]=  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                     1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,
                     1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
                     1,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,
                     1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,
                     1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                     1,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,
                     1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                     1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

void drawline_mod(int map[20][20], int x, int y, int x2, int y2) {
    int dx = abs(x - x2);
    int dy = abs(y - y2);
    double s = double(.99/(dx>dy?dx:dy));
    double t = 0.0;
    while(t < 1.0) {
        dx = int((1.0 - t)*x + t*x2);
        dy = int((1.0 - t)*y + t*y2);
        if (map[dy][dx] != 1) {
            map[dy][dx] = 5;
        } else {
            return;
        }
        t += s;
    }
}
*/
    void drawline(int **map, int width, int height, int x, int y, int x2, int y2) {
        int dx = abs(x - x2);
        int dy = abs(y - y2);
        double s = double(0.99/(dx>dy?dx:dy));
        double t = 0.0;
        while(t < 1.0) {
            dx = int((1.0 - t)*x + t*x2);
            dy = int((1.0 - t)*y + t*y2);
            //if ((dx < 0)||(dy<0)){return;}
            if (map[dx][dy] == 6)
            {
                return;
            }
            if (map[dx][dy] != 1) {
                map[dx][dy] = 5;
            } else {
                map[dx][dy] = 6;
                return;
            }
            t += s;
        }
    }
/*
void los(int map[20][20], int range, int plx, int ply) {
    int x, y;
    for (double f = 0; f < 3.14*2; f += 0.05) {
        x = int(range*cos(f)) + plx;
        y = int(range*sin(f)) + ply;
        drawline_mod(map,plx,ply,x,y);
    }
}

void draw_map(int map[20][20]) {
    for (int y=0; y<20; y++) {
        for (int x=0; x<20; x++) {
            if (map[y][x] == 0) {
                printf(" ");
            } else if (map[y][x] == 1) {
                printf("X");
            } else if (map[y][x] == 5) {
                printf(".");
            } else if (map[y][x] == 3) {
                printf("@");
            }
        }
        printf("\n");
    }
}
*/
    int** getVision(int **map, int width, int height, int range, int plx, int ply)
    {
    //qDebug() << sizeof(map);
    int **newMap = new int*[width];
    for(int i = 0; i < width; ++i)
        newMap[i] = new int[height];

    for(int i=0;i<width;i++)
        for(int j=0;j<height;j++)
        {
            newMap[i][j] = map[i][j];
        }

    int x, y;
    for (double f = 0; f < 3.14*2; f += 0.05) {
        x = int(range*cos(f)) + plx;
        y = int(range*sin(f)) + ply;
        if (y<1){
        //qDebug() << x ;
        }
        //qDebug() << x <<" "<< y;
        drawline(newMap,width,height,plx,ply,x,y);
    }
/*
    std::cout << " -----------"<<std::endl;
    for(int j=0;j<height;j++)
    {
        for(int i=0;i<width;i++)
        {
            if (newMap[i][j] == 1){std::cout << "# ";}
            else if (newMap[i][j] == 5){std::cout << "* ";}
            else{std::cout << ". ";}

        }
        std::cout << std::endl;
    }
    std::cout << std::endl;*/

        return newMap;
    }

};
#endif // FOV
