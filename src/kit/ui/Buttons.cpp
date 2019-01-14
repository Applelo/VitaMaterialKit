#include <utility>


#include "Buttons.hpp"

Buttons::Buttons(Theme *theme) {
    this->theme = theme;
    this->texts = new Texts();
    this->icons = new Icons();
}

void Buttons::textDraw(std::string text, int x, int y, const char* icon) {
    if (strlen(icon) > 0) {
        icons->draw(icon, x + 15, y + 6, theme->getSecondaryRGBA().text, 30);
        texts->draw(text, x + 20 + 26 + 10, y + 10 + 2, Button, theme->getSecondaryRGBA().text);
    }
    else {
        texts->draw(text, x + 20, y + 10 + 2, Button, theme->getSecondaryRGBA().text);
    }
}


void Buttons::outlinedDraw(std::string text, int x, int y, const char *icon) {
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


void Buttons::containedDraw(std::string text, int x, int y, const char *icon) {
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

//void Buttons::floatDraw(char *icon, int x, int y) {

//}

//void Buttons::floatDraw(char *icon, char *text, int x, int y) {

//}

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

