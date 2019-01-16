#include <utility>


#include "Buttons.hpp"

Buttons::Buttons(Theme *theme) {
    this->theme = theme;
    this->texts = new Texts();
    this->icons = new Icons();
}

Buttons::Buttons(Theme *theme, Texts *texts, Icons *icons) {
    this->theme = theme;
    this->texts = texts;
    this->icons = icons;
}

TouchZoneEvent Buttons::textDraw(const char *text, int x, int y, const char* icon) {
    textData = texts->getTextData(text, Button);
    touchZoneEvent.x = x;
    touchZoneEvent.y = y;

    if (strlen(icon) > 0) {
        icons->draw(icon, x + 15, y + 6, theme->getSecondaryRGBA().text, 30);
        texts->draw(x + 56, y + 12, Button, theme->getSecondaryRGBA().text, text);

        touchZoneEvent.width = textData.width + 76;
        touchZoneEvent.height = textData.height + 20;
    }
    else {
        texts->draw(x + 20, y + 12, Button, theme->getSecondaryRGBA().text, text);

        touchZoneEvent.width = textData.width + 40;
        touchZoneEvent.height = textData.height + 20;
    }


    return touchZoneEvent;
}


TouchZoneEvent Buttons::outlinedDraw(const char *text, int x, int y, const char *icon) {
    textData = texts->getTextData(text, Button);
    touchZoneEvent.x = x;
    touchZoneEvent.y = y;

    if (strlen(icon) > 0) {
        this->drawOutlinedRectangle(x, y, textData.width + 76, textData.height + 20, theme->getSecondaryRGBA().normal);
        this->textDraw(text, x, y, icon);
    }
    else {
        this->drawOutlinedRectangle(x, y, textData.width + 40, textData.height + 20, theme->getSecondaryRGBA().normal);
        this->textDraw(text, x, y, icon);
    }

    return touchZoneEvent;
}


TouchZoneEvent Buttons::containedDraw(const char *text, int x, int y, const char *icon) {
    textData = texts->getTextData(text, Button);
    touchZoneEvent.x = x;
    touchZoneEvent.y = y;

    if (strlen(icon) > 0) {
        vita2d_draw_rectangle(x, y, textData.width + 76, textData.height + 20, theme->getSecondaryRGBA().normal);
        this->textDraw(text, x, y, icon);

        touchZoneEvent.width = textData.width + 76;
        touchZoneEvent.height = textData.height + 20;
    }
    else {
        vita2d_draw_rectangle(x, y, textData.width + 40, textData.height + 20, theme->getSecondaryRGBA().normal);
        this->textDraw(text, x, y, icon);

        touchZoneEvent.width = textData.width + 40;
        touchZoneEvent.height = textData.height + 20;
    }

    return touchZoneEvent;
}

TouchZoneEvent Buttons::floatDraw(const char *icon, int x, int y, const char *text) {
    touchZoneEvent.x = x;
    touchZoneEvent.y = y;

    if (strlen(text) > 0) {
        textData = texts->getTextData(text, Button);
        int circleHeight = (textData.height + 20) / 2;

        vita2d_draw_fill_circle(x + circleHeight, y + circleHeight, circleHeight, theme->getSecondaryRGBA().normal);
        vita2d_draw_rectangle(x + textData.height, y, textData.width + 30, textData.height + 20, theme->getSecondaryRGBA().normal);
        vita2d_draw_fill_circle(x + circleHeight + textData.width + 30, y + circleHeight, circleHeight, theme->getSecondaryRGBA().normal);

        this->textDraw(text, x, y, icon);

        touchZoneEvent.width = textData.width + 76;
        touchZoneEvent.height = textData.height + 20;
    }
    else {
        vita2d_draw_fill_circle(x + 25, y + 25, 25, theme->getSecondaryRGBA().normal);
        icons->draw(icon, x + 10, y + 8, theme->getSecondaryRGBA().text, 30);

        touchZoneEvent.width = 50;
        touchZoneEvent.height = 50;
    }

    return touchZoneEvent;
}



void Buttons::drawOutlinedRectangle(int x, int y, int w, int h, unsigned int color) {
    x += 1;
    y += 1;
    w -= 1;
    h -= 1;
    vita2d_draw_line(x, y, x + w, y, color); //top
    vita2d_draw_line(x + w, y, x + w, y + h, color); //right
    vita2d_draw_line(x, y + h, x + w, y + h, color); //bottom
    vita2d_draw_line(x, y, x, y + h, color); //left
}

