#ifndef OPDRACHT_2_LOWERCASEPLUGIN_HPP
#define OPDRACHT_2_LOWERCASEPLUGIN_HPP

#include "IPlugin.hpp"

extern "C" {
__declspec(dllexport) sp::IPlugin* create_instance();
}

class LowercasePlugin : public sp::IPlugin
{
    public:
        std::string name() const override;

        std::string description() const override;

        std::string handle(const std::string& text) const override;
};


#endif //OPDRACHT_2_LOWERCASEPLUGIN_HPP
