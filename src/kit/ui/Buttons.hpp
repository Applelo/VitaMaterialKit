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

    void drawOutlinedRectangle(int x, int y, int w, int h, unsigned int color);
public:
    Buttons(Theme *theme);

    void textDraw(const char *text, int x, int y, const char* icon = "");

    void outlinedDraw(const char *text, int x, int y, const char* icon = "");

    void containedDraw(const char *text, int x, int y, const char *icon = "");

    void floatDraw(const char *icon, int x, int y, const char *text = "");

};


#endif //VITA_MATERIAL_KIT_BUTTON_HPP
