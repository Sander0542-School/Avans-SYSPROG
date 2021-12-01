#include "vector_helpers.hpp"
#include "random_util.hpp"

std::vector<std::string> vh::pick_random(const std::vector<std::string>& vector, int count)
{
    std::vector<std::string> result{};
    for (int i = 0; i < count; ++i)
    {
        std::string component{vector[random_util::Next(0, vector.size() - 1)]};
        result.push_back(component);
    }

    return result;
}
