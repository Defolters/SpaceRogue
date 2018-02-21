#pragma once

//! Класс, который содержит карту местности. В папке field так же могут быть служебные классы для генерации карты и проч..
// Что у нас будет местностью? Космический корабль/станция?
class Map
{
public:
    Map();
    virtual ~Map();
    void setDifficulty();
    void generateMap();
    void setPlayer();

private:
    //!< data structure that contains map
    //!< data with all objects
    //!< data with alive objects
};

/*
http://pcg.wikidot.com/pcg-algorithm:dungeon-generation
http://pcg.wikidot.com/
http://www.gamedev.ru/code/articles/levelgen1
https://www.rockpapershotgun.com/2015/07/28/how-do-roguelikes-generate-levels/
https://habrahabr.ru/post/275727/
*/
