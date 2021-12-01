#include "random_util.hpp"

random_util random_util::_instance{};

random_util::random_util() : _randomDevice(std::random_device()), _engine{_randomDevice()}
{
}

int random_util::Next(int min, int max)
{
    std::uniform_int_distribution<int> dist{min, max};
    return dist(_instance._engine);
}

double random_util::NextDouble(double min, double max)
{
    std::uniform_real_distribution<double> dist{min, max};
    return dist(_instance._engine);
}

double random_util::NextDouble()
{
    std::uniform_real_distribution<double> dist{0, 1};
    return dist(_instance._engine);
}

bool random_util::NextBoolean()
{
    std::uniform_int_distribution<int> dist{0, 1};
    return dist(_instance._engine) == 0;
}