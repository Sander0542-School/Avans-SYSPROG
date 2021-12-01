#ifndef OPDRACHT_3_CRASHPLUGIN_HPP
#define OPDRACHT_3_CRASHPLUGIN_HPP

#include "IPlugin.hpp"

extern "C" {
__declspec(dllexport) sp::IPlugin* create_instance();
}

class CrashPlugin : public sp::IPlugin
{
    public:
        std::string name() const override;

        std::string description() const override;

        int handle(const std::string& text) const override;
};


#endif //OPDRACHT_3_CRASHPLUGIN_HPP
