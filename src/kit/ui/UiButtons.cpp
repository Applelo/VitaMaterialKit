#include <utility>


#include "UiButtons.hpp"

UiButtons::UiButtons(UiTheme *theme) {
    this->theme = theme;
    this->texts = new UiTexts();
    this->icons = new UiIcons();
}

UiButtons::UiButtons(UiTheme *theme, UiTexts *texts, UiIcons *icons) {
    this->theme = theme;
    this->texts = texts;
    this->icons = icons;
}

void UiButtons::textDraw(std::string text, int x, int y, const char* icon) {
    if (strlen(icon) > 0) {
        icons->draw(icon, x + 15, y + 6, ICON_SECONDARY, 30);
        texts->draw(x + 56, y + 12, Button, TEXT_SECONDARY, text);
    }
    else {
        texts->draw(x + 20, y + 12, Button, TEXT_SECONDARY, text);
    }
}


void UiButtons::outlinedDraw(std::string text, int x, int y, const char *icon) {
    TextData textData = texts->getTextData(text, Button);
    if (strlen(icon) > 0) {
        this->drawOutlinedRectangle(x, y, textData.width + 76, textData.height + 20, theme->getSecondaryRGBA().normal);
        this->textDraw(text, x, y, icon);
    }
    else {
        this->drawOutlinedRectangle(x, y, textData.width + 40, textData.height + 20, theme->getSecondaryRGBA().normal);
        this->textDraw(text, x, y, icon);
    }
}


void UiButtons::containedDraw(std::string text, int x, int y, const char *icon) {
    TextData textData = texts->getTextData(text, Button);

    if (strlen(icon) > 0) {
        vita2d_draw_rectangle(x, y, textData.width + 76, textData.height + 20, theme->getSecondaryRGBA().normal);
        this->textDraw(text, x, y, icon);
    }
    else {
        vita2d_draw_rectangle(x, y, textData.width + 40, textData.height + 20, theme->getSecondaryRGBA().normal);
        this->textDraw(text, x, y, icon);
    }
}

void UiButtons::floatDraw(const char *icon, int x, int y, std::string text) {
    if (text.length() > 0) {
        TextData textData = texts->getTextData(text, Button);
        int circleHeight = (textData.height + 20) / 2;

        vita2d_draw_fill_circle(x + circleHeight, y + circleHeight, circleHeight, theme->getSecondaryRGBA().normal);
        vita2d_draw_rectangle(x + textData.height, y, textData.width + 30, textData.height + 20, theme->getSecondaryRGBA().normal);
        vita2d_draw_fill_circle(x + circleHeight + textData.width + 30, y + circleHeight, circleHeight, theme->getSecondaryRGBA().normal);

        this->textDraw(text, x, y, icon);
    }
    else {
        vita2d_draw_fill_circle(x + 25, y + 25, 25, theme->getSecondaryRGBA().normal);
        icons->draw(icon, x + 10, y + 8, ICON_SECONDARY, 30);
    }
}



void UiButtons::drawOutlinedRectangle(int x, int y, int w, int h, unsigned int color) {
    x += 1;
    y += 1;
    w -= 1;
    h -= 1;
    vita2d_draw_line(x, y, x + w, y, color); //top
    vita2d_draw_line(x + w, y, x + w, y + h, color); //right
    vita2d_draw_line(x, y + h, x + w, y + h, color); //bottom
    vita2d_draw_line(x, y, x, y + h, color); //left
}


