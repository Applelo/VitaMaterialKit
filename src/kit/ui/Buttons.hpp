#ifndef VITA_MATERIAL_KIT_BUTTON_HPP
#define VITA_MATERIAL_KIT_BUTTON_HPP

#include "../utils/Touch.hpp"
#include "../utils/Pad.hpp"

#include "Texts.hpp"
#include "Icons.hpp"
#include "Theme.hpp"
#include "../core/UiEvent.hh"

class Buttons final : public UiEvent {
private:
    Icons *icons;
    Texts *texts;
    Theme *theme;
    TouchZoneEvent touchZoneEvent;
    TextData textData;

    void drawOutlinedRectangle(int x, int y, int w, int h, unsigned int color);
public:
    Buttons(Theme *theme);
    Buttons(Theme *theme, Texts *texts, Icons *icons);

    TouchZoneEvent textDraw(const char *text, int x, int y, const char* icon = "");

    TouchZoneEvent outlinedDraw(const char *text, int x, int y, const char* icon = "");

    TouchZoneEvent containedDraw(const char *text, int x, int y, const char *icon = "");

    TouchZoneEvent floatDraw(const char *icon, int x, int y, const char *text = "");

};


#endif //VITA_MATERIAL_KIT_BUTTON_HPP
