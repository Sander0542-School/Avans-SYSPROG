#include "RemoveConsonantsPlugin.hpp"

#include <algorithm>
#include <array>
#include <sstream>

std::string RemoveConsonantsPlugin::name() const
{
    return "Remove Consonants";
}

std::string RemoveConsonantsPlugin::description() const
{
    return "Removes all consonants from the text.";
}

std::string RemoveConsonantsPlugin::handle(const std::string& text) const
{
    std::array<char, 10> a{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    std::sort(a.begin(), a.end());

    std::stringstream result{};

    for (const auto& character: text)
    {
        if (std::binary_search(a.begin(), a.end(), character))
            result << character;
    }

    return result.str();
}

sp::IPlugin* create_instance()
{
    return new RemoveConsonantsPlugin;
}
