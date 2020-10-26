#ifndef CONFIG_H
#define CONFIG_H
#include <iostream>
#include <fstream>

namespace herbglitch {
    namespace config {
        template <class ConfigObj>
        void load(std::string filepath, ConfigObj *configObj);
    }
}

#endif // TEXTURE_H