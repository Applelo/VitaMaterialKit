#ifndef VITA_MATERIAL_KIT_UI_BUTTON_HPP
#define VITA_MATERIAL_KIT_UI_BUTTON_HPP

#include "../utils/Touch.hpp"
#include "../utils/Pad.hpp"

#include "UiTexts.hpp"
#include "UiIcons.hpp"
#include "Theme.hpp"

class UiButtons {
private:
    UiIcons *icons;
    Texts *texts;
    Theme *theme;

    void drawOutlinedRectangle(int x, int y, int w, int h, unsigned int color);
public:
    UiButtons(Theme *theme);

    void textDraw(std::string text, int x, int y, const char* icon = "");

    void outlinedDraw(std::string text, int x, int y, const char* icon = "");

    void containedDraw(std::string text, int x, int y, const char *icon = "");

    void floatDraw(const char *icon, int x, int y, std::string text = "");

};


#endif //VITA_MATERIAL_KIT_BUTTON_HPP
