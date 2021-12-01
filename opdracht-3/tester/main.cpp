#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <memory>

#include "PluginWrapper.hpp"
#include "IPlugin.hpp"

int main(int argc, char* argv[])
{
    try
    {
        using factory = sp::IPlugin* (*)();
        sp::PluginWrapper wrapper{"plugins/" + std::string(argv[1])};
        factory func = reinterpret_cast<factory>(wrapper.lookup("create_instance"));
        std::unique_ptr<sp::IPlugin> plugin{func()};

        std::cout << "Plugin name: " << plugin->name() << std::endl;
        std::cout << "Plugin description: " << plugin->description() << std::endl;
        std::cout << "Plugin text output: " << plugin->handle("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") << std::endl;
    }
    catch (const std::exception& ex)
    {
        return 1;
    }
    return 0;
}
