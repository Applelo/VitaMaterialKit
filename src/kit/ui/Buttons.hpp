#ifndef VITA_MATERIAL_KIT_BUTTON_HPP
#define VITA_MATERIAL_KIT_BUTTON_HPP

#include "../utils/Touch.hpp"
#include "../utils/Pad.hpp"

#include "Texts.hpp"
#include "Icons.hpp"
#include "Theme.hpp"

class Buttons {
private:
    Icons *icons;
    Texts *texts;
    Theme *theme;
public:
    Buttons(Theme *theme);

    void textDraw(std::string text, int x, int y, const char* icon);

    //void outlinedDraw(char *text, int x, int y);
    //void outlinedDraw(char* icon, char *text, int x, int y);

    void containedDraw(std::string text, int x, int y, const char *icon = "");

    //void floatDraw(char *icon, int x, int y);
    //void floatDraw(char* icon, char *text, int x, int y);

};


#endif //VITA_MATERIAL_KIT_BUTTON_HPP
