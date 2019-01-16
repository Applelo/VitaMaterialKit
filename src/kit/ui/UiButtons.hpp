#ifndef VITA_MATERIAL_KIT_BUTTON_HPP
#define VITA_MATERIAL_KIT_BUTTON_HPP

#include "../utils/Touch.hpp"
#include "../utils/Pad.hpp"

#include "UiTexts.hpp"
#include "UiIcons.hpp"
#include "UiTheme.hpp"
#include "../core/UiEvent.hh"

class UiButtons final : public UiEvent {
private:
    UiIcons *icons;
    UiTexts *texts;
    UiTheme *theme;
    TouchZoneEvent touchZoneEvent;
    TextData textData;

    void drawOutlinedRectangle(int x, int y, int w, int h, unsigned int color);
public:
    UiButtons();
    UiButtons(UiTheme *theme, UiTexts *texts, UiIcons *icons);

    TouchZoneEvent textDraw(const char *text, int x, int y, const char* icon = "");

    TouchZoneEvent outlinedDraw(const char *text, int x, int y, const char* icon = "");

    TouchZoneEvent containedDraw(const char *text, int x, int y, const char *icon = "");

    TouchZoneEvent floatDraw(const char *icon, int x, int y, const char *text = "");

};


#endif //VITA_MATERIAL_KIT_BUTTON_HPP
