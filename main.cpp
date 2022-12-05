#include "Map.hpp"
#include <iostream>

#define DEBUG

#ifdef DEBUG

int main()
{
    Map::Map2D map;
    map.initialize(2); // initialize the map with perlinnoise with the seed 123456u.
    map.cellularAutomaton();
    getchar();
    getchar();
    return 0;
}

#endif
