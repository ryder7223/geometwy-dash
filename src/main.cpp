#include <Geode/Geode.hpp>
#include <Geode/modify/CCLabelBMFont.hpp>
#include <cctype>

using namespace geode::prelude;

class $modify(CCLabelBMFont) {
    static CCLabelBMFont* create(char const* str, char const* fntFile) {
        std::string owoStr(str);

        // idk if this is the best way to do this 
        for (char& c : owoStr) {
            if (std::tolower(c) == 'r' || std::tolower(c) == 'l') {
                c = 'w';
            }
        }
        bool owoConfig = Mod::get()->getSettingValue<bool>("owoo");
        if (owoConfig)  return CCLabelBMFont::create((owoStr + " uwu").c_str(), fntFile);

        return CCLabelBMFont::create(owoStr.c_str(), fntFile);
        
    }
};
