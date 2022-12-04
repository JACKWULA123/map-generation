#ifndef PERLINNOISE_HPP
#define PERLINNOISE_HPP
#include "Perlinnoise.hpp"
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#ifndef TIME_H
#define TIME_H
#include <time.h>
#endif

#define kDefaultMapSize 120

namespace Map
{
    class Map2D
    {
    private:
        double map[kDefaultMapSize][kDefaultMapSize]; // map matrix. current: >0.5 seawater
    public:                                           //                      <0.5 land
        // constructor with size.
        Map2D() {}
        // destructor.
        ~Map2D() {}

        void print() // print the map
        {
            system("cls");
            for (int i = 1; i < kDefaultMapSize - 1; i++)
            {
                for (int j = 1; j < kDefaultMapSize - 1; j++)
                {
                    if (map[i][j] >= 0.5)
                    {
                        printf("##");
                    }
                    else
                    {
                        printf("  ");
                    }
                }
                printf("\n");
            }
        }

        void initialize(int _k, uint_fast32_t _seed) // initialize the map matrix
        {                                            // _k is the way of the noise generate algorithm.
                                                     // 1 is for PerlinNoise.
            // for (int i = 0; i < kDefaultMapSize; i++)
            // { // set the map edge.
            //     map[0][i] = -1;
            //     map[kDefaultMapSize - 1][i] = -1;
            //     map[i][0] = -1;
            //     map[i][kDefaultMapSize - 1] = -1;
            // }
            if (_k == 1)
            {
                const siv::PerlinNoise::seed_type seed = _seed;
                const siv::PerlinNoise perlin{seed};
                for (int i = 1; i < kDefaultMapSize - 1; i++)
                {
                    for (int j = 1; j < kDefaultMapSize - 1; j++)
                    {
                        map[i][j] = perlin.octave2D_01((i * 0.01), (j * 0.01), 4);
                    }
                }
            }
            else if (_k == 2)
            {
                srand((unsigned int)time(NULL));
                for (int i = 0; i <= kDefaultMapSize - 1; i++)
                {
                    for (int j = 0; j <= kDefaultMapSize - 1; j++)
                    {
                        if (i == 0 || j == 0 || i == kDefaultMapSize - 1 || j == kDefaultMapSize - 1)
                        {
                            map[i][j] = 0.6;
                        }
                        else
                        {
                            if (rand() % 100 < 64)
                            {
                                map[i][j] = 0.6;
                            }
                            else
                            {
                                map[i][j] = 0.4;
                            }
                        }
                    }
                }
            }

            print();
        }

        int getNumLand(int _i, int _j) // >0.5 : land
        {
            int ans = 0;
            if (map[_i - 1][_j - 1] > 0.5)
                ans++;
            if (map[_i - 1][_j] > 0.5)
                ans++;
            if (map[_i - 1][_j + 1] > 0.5)
                ans++;
            if (map[_i][_j - 1] > 0.5)
                ans++;
            if (map[_i][_j + 1] > 0.5)
                ans++;
            if (map[_i + 1][_j - 1] > 0.5)
                ans++;
            if (map[_i + 1][_j] > 0.5)
                ans++;
            if (map[_i + 1][_j + 1] > 0.5)
                ans++;
            return ans;
        }

        void cellularAutomaton(int _max = 4, int _k = 2) // if more than _max blocks around map[i][j] are > 0.5, then its land.
                                                         // if less than _max blocks around map[i][j] are > 0.5, then its seawater.
        {
            // iterate _k times.
            for (int k = 0; k < _k; k++)
            {
                for (int i = 1; i < kDefaultMapSize - 1; i++)
                {
                    for (int j = 1; j < kDefaultMapSize - 1; j++)
                    {
                        if (getNumLand(i, j) > _max)
                        {
                            map[i][j] = 0.6;
                        }
                        else
                        {
                            map[i][j] = 0.4;
                        }
                    }
                }
                print();
            }
        }
    };
} // namespace Map
