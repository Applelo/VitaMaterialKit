#ifndef VITA_MATERIAL_KIT_UI_BUTTON_HPP
#define VITA_MATERIAL_KIT_UI_BUTTON_HPP

#include "../utils/Touch.hpp"
#include "../utils/Pad.hpp"

#include "UiTexts.hpp"
#include "UiIcons.hpp"
#include "UiTheme.hpp"

class UiButtons {
private:
    UiIcons *icons;
   UiTexts *texts;
    UiTheme *theme;

    void drawOutlinedRectangle(int x, int y, int w, int h, unsigned int color);
public:
    UiButtons(UiTheme *theme);
    UiButtons(UiTheme *theme, UiTexts *texts, UiIcons *icons);

    void textDraw(std::string text, int x, int y, const char* icon = "");

    void outlinedDraw(std::string text, int x, int y, const char* icon = "");

    void containedDraw(std::string text, int x, int y, const char *icon = "");

    void floatDraw(const char *icon, int x, int y, std::string text = "");

};


#endif //VITA_MATERIAL_KIT_UI_BUTTON_HPP
