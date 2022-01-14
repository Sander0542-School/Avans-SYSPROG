#ifndef OPDRACHT_5_RANDOMUTIL_HPP
#define OPDRACHT_5_RANDOMUTIL_HPP

#include <random>

class RandomUtil
{
    private:
        static RandomUtil _instance;
        std::random_device _randomDevice;
        std::default_random_engine _engine;

        RandomUtil();

    public:
        /**
         * @brief Get a random int between a minimum and maximum value.
         * @param min The minimum value.
         * @param max The maximum value.
         * @return The random int.
         */
        static int Next(int min, int max);
};

#endif //OPDRACHT_5_RANDOMUTIL_HPP
