#include "config.hpp"

namespace herbglitch {
    namespace config {
        template <class ConfigObj>
        void load(std::string filepath, ConfigObj *configObj) {
            std::filebuf fb;
            if (fb.open(filepath, std::ios::in)) {
                std::istream is(&fb);
                while (is) {
                    std::string temp;
                    std::getline(is, temp);
                    std::cout << temp << std::endl;
                    configObj.load(temp.substr(0, temp.find(':') - 1), temp.substr(temp.find(':') + 1), temp.size() - 1);
                }
                fb.close();
            }
        }
    }
}