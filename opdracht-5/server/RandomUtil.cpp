#include "RandomUtil.hpp"

RandomUtil RandomUtil::_instance{};
const std::string PossibleRandomCharacters{"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};

RandomUtil::RandomUtil() : _randomDevice(std::random_device{}), _engine{_randomDevice()}
{
}

int RandomUtil::Next(int min, int max)
{
    std::uniform_int_distribution<int> dist{min, max};
    return dist(_instance._engine);
}