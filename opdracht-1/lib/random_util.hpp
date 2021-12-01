#ifndef OPDRACHT_1_RANDOM_UTIL_HPP
#define OPDRACHT_1_RANDOM_UTIL_HPP

#include <random>

class random_util
{
    private:
        static random_util _instance;
        std::random_device _randomDevice;
        std::default_random_engine _engine;

        random_util();

    public:
        static int Next(int min, int max);

        static double NextDouble(double min, double max);

        static double NextDouble();

        static bool NextBoolean();

        random_util& operator=(const random_util& util) = delete;

        random_util(const random_util& randomUtil) = delete;

        random_util& operator=(random_util&& randomUtil) = delete;

        random_util(random_util&& randomUtil) = delete;
};


#endif //OPDRACHT_1_RANDOM_UTIL_HPP
