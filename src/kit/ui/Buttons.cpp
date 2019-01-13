#include <utility>


#include "Buttons.hpp"

Buttons::Buttons(Theme *theme) {
    this->theme = theme;
    this->texts = new Texts();
    this->icons = new Icons();
}

void Buttons::textDraw(std::string text, int x, int y, const char* icon) {
    if (icon) {
        icons->draw(icon, x + 10, y + 10, theme->getSecondaryRGBA().text, 24);
        texts->draw(std::move(text), x + 48, y, Button, theme->getSecondaryRGBA().text, false);
    }
    else {

    }
}


//void Buttons::outlinedDraw(char *icon, char *text, int x, int y, const char *icon) {

//}

//rework after to use textDraw instead + add container
void Buttons::containedDraw(std::string text, int x, int y, const char *icon) {
    TextData textData = texts->getTextData(text, Button);
    vita2d_draw_rectangle(x, y, textData.width, textData.height, theme->getSecondaryRGBA().normal);
    texts->draw(text, x, y, Button, theme->getSecondaryRGBA().text);
}

//void Buttons::floatDraw(char *icon, int x, int y) {

//}

//void Buttons::floatDraw(char *icon, char *text, int x, int y) {

//}

