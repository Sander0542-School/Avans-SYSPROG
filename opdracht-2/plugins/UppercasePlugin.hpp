#ifndef OPDRACHT_2_UPPERCASEPLUGIN_HPP
#define OPDRACHT_2_UPPERCASEPLUGIN_HPP

#include "IPlugin.hpp"

extern "C" {
__declspec(dllexport) sp::IPlugin* create_instance();
}

class UppercasePlugin : public sp::IPlugin
{
    public:
        std::string name() const override;

        std::string description() const override;

        std::string handle(const std::string& text) const override;
};


#endif //OPDRACHT_2_UPPERCASEPLUGIN_HPP
