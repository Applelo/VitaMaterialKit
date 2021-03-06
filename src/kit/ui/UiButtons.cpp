#include "UiButtons.hh"

UiButtons::UiButtons(UiTheme *theme) {
    this->theme = theme;
    this->texts = new UiTexts();
    this->icons = new UiIcons();
}

UiButtons::UiButtons(UiTheme *theme, TextStyle textStyle) {
    this->theme = theme;
    this->texts = new UiTexts();
    this->icons = new UiIcons();
    this->textStyle = textStyle;
}

UiButtons::UiButtons(UiTheme *theme, UiTexts *texts, UiIcons *icons) {
    this->theme = theme;
    this->texts = texts;
    this->icons = icons;
}

UiButtons::UiButtons(UiTheme *theme, UiTexts *texts, UiIcons *icons, TextStyle textStyle) {
    this->theme = theme;
    this->texts = texts;
    this->icons = icons;
    this->textStyle = textStyle;
}

void UiButtons::textDrawFinal(std::string text, int x, int y, TypeTheme typeTheme, const char *icon) {
    if (strlen(icon) > 0) {
        icons->draw(icon, x + 15, y + 6, typeTheme == THEME_PRIMARY ? THEME_PRIMARY : THEME_SECONDARY, 30);
        texts->draw(x + 56, y + 12, textStyle, typeTheme == THEME_PRIMARY ? THEME_PRIMARY : THEME_SECONDARY, text);

        zoneEvent.width = textData.width + 76;
        zoneEvent.height = textData.height + 20;
    }
    else {
        texts->draw(x + 20, y + 12, textStyle, typeTheme == THEME_PRIMARY ? THEME_PRIMARY : THEME_SECONDARY, text);

        zoneEvent.width = textData.width + 40;
        zoneEvent.height = textData.height + 20;
    }

}

ZoneEvent UiButtons::textDraw(std::string text, int x, int y, TypeTheme typeTheme, bool selected, const char* icon) {
    textData = texts->getTextData(text, textStyle);

    if (selected) {
        if (strlen(icon) > 0) {
            vita2d_draw_rectangle(x, y, textData.width + 76, textData.height + 20, typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().light : theme->getSecondaryRGBA().light);
        }
        else {
            vita2d_draw_rectangle(x, y, textData.width + 40, textData.height + 20, typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().light : theme->getSecondaryRGBA().light);
        }
    }

    this->textDrawFinal(text, x, y, typeTheme, icon);

    zoneEvent.x = x;
    zoneEvent.y = y;
    zoneEvent.selector = selected;

    return zoneEvent;
}


ZoneEvent UiButtons::outlinedDraw(std::string text, int x, int y, TypeTheme typeTheme, bool selected, const char *icon) {
    textData = texts->getTextData(text, textStyle);

    if (strlen(icon) > 0) {
        if (selected) {
            this->drawOutlinedRectangle(x, y, textData.width + 76, textData.height + 20, BUTTONS_OUTLINED_SIZE, typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().light : theme->getSecondaryRGBA().light);
        }
        else {
            this->drawOutlinedRectangle(x, y, textData.width + 76, textData.height + 20, BUTTONS_OUTLINED_SIZE, typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().normal : theme->getSecondaryRGBA().normal);
        }

        this->textDrawFinal(text, x, y, typeTheme == THEME_PRIMARY ? THEME_PRIMARY : THEME_SECONDARY, icon);
    }
    else {
        if (selected) {
            this->drawOutlinedRectangle(x, y, textData.width + 40, textData.height + 20, BUTTONS_OUTLINED_SIZE, typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().light : theme->getSecondaryRGBA().light);
        }
        else {
            this->drawOutlinedRectangle(x, y, textData.width + 40, textData.height + 20, BUTTONS_OUTLINED_SIZE, typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().normal : theme->getSecondaryRGBA().normal);
        }

        this->textDrawFinal(text, x, y, typeTheme == THEME_PRIMARY ? THEME_PRIMARY : THEME_SECONDARY);
    }

    zoneEvent.x = x;
    zoneEvent.y = y;
    zoneEvent.selector = selected;
    return zoneEvent;
}


ZoneEvent UiButtons::containedDraw(std::string text, int x, int y, TypeTheme typeTheme, bool selected, const char *icon) {
    textData = texts->getTextData(text, textStyle);

    if (strlen(icon) > 0) {
        if (selected) {
            vita2d_draw_rectangle(x, y, textData.width + 76, textData.height + 20, typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().light : theme->getSecondaryRGBA().light);
        }
        else {
            vita2d_draw_rectangle(x, y, textData.width + 76, textData.height + 20, typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().normal : theme->getSecondaryRGBA().normal);
        }

        this->textDrawFinal(text, x, y, typeTheme == THEME_PRIMARY ? THEME_PRIMARY : THEME_SECONDARY, icon);

        zoneEvent.width = textData.width + 76;
        zoneEvent.height = textData.height + 20;
    }
    else {
        if (selected) {
            vita2d_draw_rectangle(x, y, textData.width + 40, textData.height + 20, typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().light : theme->getSecondaryRGBA().light);
        }
        else {
            vita2d_draw_rectangle(x, y, textData.width + 40, textData.height + 20, typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().normal : theme->getSecondaryRGBA().normal);
        }

        this->textDrawFinal(text, x, y, typeTheme == THEME_PRIMARY ? THEME_PRIMARY : THEME_SECONDARY);

        zoneEvent.width = textData.width + 40;
        zoneEvent.height = textData.height + 20;
    }

    zoneEvent.x = x;
    zoneEvent.y = y;
    zoneEvent.selector = selected;

    return zoneEvent;
}

ZoneEvent UiButtons::floatDraw(const char *icon, int x, int y, TypeTheme typeTheme, bool selected, std::string text) {

    if (text.length() > 0) {
        textData = texts->getTextData(text, textStyle);
        circleHeight = (textData.height + 20) / 2;

        if (selected) {
            vita2d_draw_fill_circle(x + circleHeight, y + circleHeight, circleHeight, typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().light : theme->getSecondaryRGBA().light);
            vita2d_draw_rectangle(x + textData.height, y, textData.width + 30, textData.height + 20, typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().light : theme->getSecondaryRGBA().light);
            vita2d_draw_fill_circle(x + circleHeight + textData.width + 30, y + circleHeight, circleHeight, typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().light : theme->getSecondaryRGBA().light);
        }
        else {
            vita2d_draw_fill_circle(x + circleHeight, y + circleHeight, circleHeight, typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().normal : theme->getSecondaryRGBA().normal);
            vita2d_draw_rectangle(x + textData.height, y, textData.width + 30, textData.height + 20, typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().normal : theme->getSecondaryRGBA().normal);
            vita2d_draw_fill_circle(x + circleHeight + textData.width + 30, y + circleHeight, circleHeight, typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().normal : theme->getSecondaryRGBA().normal);
        }

        this->textDrawFinal(text, x, y, typeTheme, icon);

        zoneEvent.width = textData.width + 76;
        zoneEvent.height = textData.height + 20;
    }
    else {
        if (selected) {
            vita2d_draw_fill_circle(x + 35, y + 35, 35, typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().light : theme->getSecondaryRGBA().light);
        }
        else {
            vita2d_draw_fill_circle(x + 35, y + 35, 35, typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().normal : theme->getSecondaryRGBA().normal);
        }

        icons->draw(icon, x + 16, y + 14, typeTheme == THEME_PRIMARY ? THEME_PRIMARY : THEME_SECONDARY, 40);

        zoneEvent.width = 70;
        zoneEvent.height = 70;
    }

    zoneEvent.x = x;
    zoneEvent.y = y;
    zoneEvent.selector = selected;

    return zoneEvent;
}



void UiButtons::drawOutlinedRectangle(int x, int y, int w, int h, unsigned int size, unsigned int color) {

    vita2d_draw_rectangle(x, y, w, size, color);//top
    vita2d_draw_rectangle(x + w - size, y, size, h, color); //right
    vita2d_draw_rectangle(x, y + h - size, w, size, color); //bottom
    vita2d_draw_rectangle(x, y, size, h, color); //left

}




