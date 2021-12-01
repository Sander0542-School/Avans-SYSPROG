#include "CrashPlugin.hpp"

#include <stdexcept>

std::string CrashPlugin::name() const
{
    return "Crash";
}

std::string CrashPlugin::description() const
{
    return "A plugin that crashes in the handle method";
}

int CrashPlugin::handle(const std::string& text) const
{
    return 69;
}

sp::IPlugin* create_instance()
{
    return new CrashPlugin;
}
