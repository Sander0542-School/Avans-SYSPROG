#ifndef OPDRACHT_3_IPLUGIN_HPP
#define OPDRACHT_3_IPLUGIN_HPP

#include <string>

namespace sp
{
    class IPlugin
    {
        public:
            virtual ~IPlugin() = default;

            virtual std::string name() const = 0;

            virtual std::string description() const = 0;

            virtual std::string handle(const std::string& text) const = 0;
    };
}

#endif //OPDRACHT_2_IPLUGIN_HPP
