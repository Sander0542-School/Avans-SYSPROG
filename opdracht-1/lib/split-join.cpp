#include "split-join.hpp"

#include <sstream>

std::vector<std::string> sp::split(const std::string& str, const std::string& sep)
{
    std::string s{str};
    size_t pos = 0;
    std::string token;
    std::vector<std::string> components{};
    while ((pos = s.find(sep)) != std::string::npos)
    {
        token = s.substr(0, pos);
        components.push_back(token);
        s.erase(0, pos + sep.length());
    }

    return components;
}

std::vector<std::string> sp::split(const std::string& str, const std::regex& sep)
{
    std::sregex_token_iterator iter(str.begin(), str.end(), sep, -1);
    std::sregex_token_iterator end;
    std::vector<std::string> components{};
    for (; iter != end; ++iter)
    {
        components.push_back(*iter);
    }

    return components;
}

std::string sp::join(const std::vector<std::string>& components, const std::string& join)
{
    std::stringstream ss{};
    for (const auto& component: components)
    {
        if (component != components[0]) ss << join;
        ss << component;
    }

    return ss.str();
}
