#include <utility>


#include "UiParentBoxButtons.hh"

UiParentBoxButtons::UiParentBoxButtons(UiTheme *theme) : theme(theme) {
    this->selectorColor = theme->convertHexToRGBA(theme->getSecondaryHEX().light, 150);
}

UiParentBoxButtons::UiParentBoxButtons(UiTheme *theme, UiIcons *icons) : theme(theme), icons(icons) {
    this->selectorColor = theme->convertHexToRGBA(theme->getSecondaryHEX().light, 150);
}

UiParentBoxButtons::UiParentBoxButtons(UiTheme *theme, UiIcons *icons, UiTexts *texts) : theme(theme), icons(icons), texts(texts) {
    this->selectorColor = theme->convertHexToRGBA(theme->getSecondaryHEX().light, 150);
}

void UiParentBoxButtons::drawSelector(int x, int y, bool selector, unsigned int size) {
    if (selector) {
        vita2d_draw_fill_circle(x + size, y + size, (int) (size * 0.75), selectorColor);
    }
}

void UiParentBoxButtons::drawBoxButton(int x, int y, const char *icon, unsigned int size) {
    this->drawBoxButtonColor(x, y, icon, theme->getSecondaryRGBA().dark, size);
}

void UiParentBoxButtons::drawBoxButtonColor(int x, int y, const char *icon, unsigned int color, unsigned int size) {
    icons->draw(icon, x + (size / 2), y + (size / 2), color, size);
}

TextData UiParentBoxButtons::drawText(int x, int y, int size, std::string text) {
    texts->draw(x + (size * 2), y + (int) (size * 0.75), Body1, text);
    return texts->getTextData(text, Body1);
}


