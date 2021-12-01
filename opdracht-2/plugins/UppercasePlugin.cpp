#include "UppercasePlugin.hpp"

#include <algorithm>

std::string UppercasePlugin::name() const
{
    return "Uppercase";
}

std::string UppercasePlugin::description() const
{
    return "Makes the text uppercase.";
}

std::string UppercasePlugin::handle(const std::string& text) const
{
    auto result = text;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);

    return result;
}

sp::IPlugin* create_instance()
{
    return new UppercasePlugin;
}
