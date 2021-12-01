#include "LowercasePlugin.hpp"

#include <algorithm>

std::string LowercasePlugin::name() const
{
    return "Lowercase";
}

std::string LowercasePlugin::description() const
{
    return "Makes the text lowercase.";
}

std::string LowercasePlugin::handle(const std::string& text) const
{
    auto result = text;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);

    return result;
}

sp::IPlugin* create_instance()
{
    return new LowercasePlugin;
}
