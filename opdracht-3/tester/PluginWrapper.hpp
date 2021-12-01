#ifndef OPDRACHT_3_PLUGINWRAPPER_HPP
#define OPDRACHT_3_PLUGINWRAPPER_HPP

#include <string>

namespace sp {
    class PluginWrapper {
        public:
            PluginWrapper(const std::string& path);
            ~PluginWrapper();

            PluginWrapper(const PluginWrapper&) = delete;
            PluginWrapper& operator=(const PluginWrapper&) = delete;

            PluginWrapper(PluginWrapper&& other);
            PluginWrapper& operator=(PluginWrapper&& other);

            void* plugin() const { return _plugin; }
            void* lookup(const std::string& symbol) const;

        private:
            void* _plugin {nullptr};

            void cleanup();
            void move(PluginWrapper&& other);
    };
}

#endif //OPDRACHT_2_PLUGINWRAPPER_HPP
