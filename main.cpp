#include "Map.hpp"
#include <iostream>

#define DEBUG

#ifdef DEBUG

int main()
{
    Map::Map2D map;
    map.initialize(1, 123456u); // initialize the map with perlinnoise with the seed 123456u.

    getchar();
    getchar();
    return 0;
}

#endif
