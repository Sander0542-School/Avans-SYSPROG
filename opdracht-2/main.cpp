#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <memory>

#include "PluginWrapper.hpp"
#include "common/IPlugin.hpp"

std::vector<std::string> scan_dir(const std::string& path, const std::string& ext)
{
    std::vector<std::string> plugins;
    for (const auto& entry: std::filesystem::directory_iterator{path})
    {
        std::string filename{entry.path().string()};
        if (filename.substr(filename.size() - ext.size(), ext.size()) == ext)
        {
            plugins.push_back(filename);
        }
    }
    return plugins;
}

std::vector<std::string> split_string(const std::string& str)
{
    std::vector<std::string> components{};

    if (str.empty()) return components;

    std::string word;
    for (auto x: str)
    {
        if (x == ' ')
        {
            components.push_back(word);
            word = "";
        }
        else
        {
            word += x;
        }
    }
    components.push_back(word);

    return components;
}

int main(int argc, char* argv[])
{
    try
    {
        // (1) scan directory for plugins
        std::vector<std::string> files{scan_dir("plugins", "plug")};

        // (2) open them
        std::vector<sp::PluginWrapper> plugins;
        for (const std::string& file: files)
        {
            plugins.emplace_back(file);
        }

        // (3) instantiate objects
        using factory = sp::IPlugin* (*)();
        std::vector<std::unique_ptr<sp::IPlugin>> objects;
        for (const sp::PluginWrapper& wrapper: plugins)
        {
            factory func = reinterpret_cast<factory>(wrapper.lookup("create_instance"));
            objects.emplace_back(func());
        }

        // (4) load text file
        std::cout << "Enter the file you want to load (lorem.txt): ";
        std::string fileName;
        std::getline(std::cin, fileName);
        if (fileName.empty()) fileName = "lorem.txt";
        std::cout << '\n';
        std::ifstream filestream("resources/" + fileName);
        std::stringstream buffer;
        buffer << filestream.rdbuf();

        // (5) select plugins
        std::cout << "Plugins: \n";
        for (int i = 0; i < objects.size(); ++i)
        {
            std::cout << '[' << i << "] " << objects[i]->name() << ": " << objects[i]->description() << '\n';
        }
        std::cout << "\nSelect plugins [ex. 0 2 1]: ";
        std::string pluginSelectionStr;
        std::getline(std::cin, pluginSelectionStr);
        std::cout << '\n';
        auto pluginSelection = split_string(pluginSelectionStr);

        if (pluginSelection.empty())
        {
            for (int i = 0; i < objects.size(); ++i)
            {
                pluginSelection.push_back(std::to_string(i));
            }
        }

        // (6) manipulate text
        auto text = buffer.str();
        for (const auto& pluginIdStr: pluginSelection)
        {
            auto pluginId = std::stoi(pluginIdStr);
            text = objects[pluginId]->handle(text);
        }

        // (7) show result
        std::cout << "Result:\n\n" << text;
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
