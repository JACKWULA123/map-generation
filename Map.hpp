#ifndef PERLINNOISE_HPP
#define PERLINNOISE_HPP
#include "Perlinnoise.hpp"
#endif

#define kDefaultMapSize 256

namespace Map
{
    class Map2D
    {
    private:
        double map[kDefaultMapSize][kDefaultMapSize]; // map matrix.
    public:
        // constructor with size.
        Map2D() {}
        // destructor.
        ~Map2D() {}

        void initialize(int _k, uint_fast32_t _seed) // initialize the map matrix
        {                                            // _k is the way of the noise generate algorithm.
                                                     // 1 is for PerlinNoise.
            for (int i = 0; i < kDefaultMapSize; i++)
            { // set the map edge.
                map[0][i] = -1;
                map[kDefaultMapSize - 1][i] = -1;
                map[i][0] = -1;
                map[i][kDefaultMapSize - 1] = -1;
            }
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
        }
    };
} // namespace Map
