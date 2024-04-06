#include <Geode/Geode.hpp>
#include <Geode/modify/CCLabelBMFont.hpp>
#include <cctype>
#include <regex>

using namespace geode::prelude;

class $modify(CCLabelBMFont) {
    static CCLabelBMFont* create(char const* str, char const* fntFile) {
        std::string owoStr(str);

        //stolen from uwufier, idk if this is the best way to do this >~<
        std::vector<std::pair<std::regex, std::string>> uwuMap = {
            {std::regex("(?:R|L)"), "W"},
            {std::regex("(?:r|l)"), "w"},
            {std::regex("n([aeiou])"), "ny$1"},
            {std::regex("N([aeiou])"), "Ny$1"},
            {std::regex("N([AEIOU])"), "Ny$1"},
            {std::regex("ove"), "uv"},
            
        };

        for (auto& rule : uwuMap) {
            owoStr = std::regex_replace(owoStr, rule.first, rule.second);
        }


        bool owoConfig = Mod::get()->getSettingValue<bool>("owoo");
        if (owoConfig)  return CCLabelBMFont::create((owoStr + " uwu").c_str(), fntFile);

        return CCLabelBMFont::create(owoStr.c_str(), fntFile);
    }
};
