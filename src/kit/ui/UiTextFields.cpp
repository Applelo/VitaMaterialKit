#include <utility>

#include "UiTextFields.hh"

UiTextFields::UiTextFields(UiTheme *theme) : theme(theme) {
    this->texts = new UiTexts();
    this->icons = new UiIcons();
    this->init();
}

UiTextFields::UiTextFields(UiTheme *theme, UiTexts *texts) : theme(theme), texts(texts) {
    this->icons = new UiIcons();
    this->init();
}

UiTextFields::UiTextFields(UiTheme *theme, UiTexts *texts, UiIcons *icons) : theme(theme), texts(texts), icons(icons) {
    this->init();
}



ZoneEventTextField UiTextFields::filledDraw(
        int x,
        int y,
        bool selector,
        std::string label,
        std::string text,
        TypeTheme typeTheme,
        std::string helperText,
        std::string errorText,
        const char *leadingIcon,
        const char *trailingIcon,
        std::string prefixText,
        std::string suffixText,
        int charCounter
        ) {

    prefixPos = 0, suffixPos = 0;

    //draw background
    vita2d_draw_rectangle(x, y, TEXTFIELD_WIDTH, TEXTFIELD_HEIGTH, selector ? TEXTFIELD_BACKGROUND_FOCUS_COLOR : TEXTFIELD_BACKGROUND_NOFOCUS_COLOR);

    //draw bar status
    if (errorText.length() > 0) {
        vita2d_draw_rectangle(x, y + (TEXTFIELD_HEIGTH - 2), TEXTFIELD_WIDTH, 2, TEXTFIELD_ERROR_COLOR);
    }
    else if (selector) {
        vita2d_draw_rectangle(x, y + (TEXTFIELD_HEIGTH - 2), TEXTFIELD_WIDTH, 2, typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().normal : theme->getSecondaryRGBA().normal);
    }
    else {
        vita2d_draw_rectangle(x, y + (TEXTFIELD_HEIGTH - 1), TEXTFIELD_WIDTH, 1, TEXTFIELD_NOFOCUSBAR_COLOR);
    }

    //draw helper
    if (errorText.length() > 0) {
        texts->draw(x + TEXTFIELD_PADDING, y + TEXTFIELD_HEIGTH + 2, bottomTextStyleData, TEXTFIELD_ERROR_COLOR, errorText);
    }
    else if (helperText.length() > 0) {
        texts->draw(x + TEXTFIELD_PADDING, y + TEXTFIELD_HEIGTH + 2, bottomTextStyleData, TEXTFIELD_HELPER_COLOR, helperText);
    }

    if (prefixText.length() > 0) {

    }

    textDataText = texts->getTextData(text, Body1);
    if (text.length() > 0) {
        if (selector) {
            texts->draw(x + TEXTFIELD_PADDING, y + 4, bottomTextStyleData, typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().normal : theme->getSecondaryRGBA().normal, std::move(label));
        }
        else {
            texts->draw(x + TEXTFIELD_PADDING, y + 4, bottomTextStyleData, std::move(label));
        }

        texts->draw(x + TEXTFIELD_PADDING, y + 30, mainTextStyleData, std::move(text));
    }
    else {
        if (selector) {
            texts->draw(x + TEXTFIELD_PADDING, y + 4, bottomTextStyleData, typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().normal : theme->getSecondaryRGBA().normal, std::move(label));
        }
        else {
            texts->draw(x + TEXTFIELD_PADDING, y + 26, Body1, errorText.length() > 0 ? TEXTFIELD_ERROR_COLOR : (typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().normal : theme->getSecondaryRGBA().normal), std::move(label));
        }
    }


    if (suffixText.length() > 0) {

    }

    return zoneEventTextField;
}

void UiTextFields::init() {
    bottomTextStyleData.size = 18;
    bottomTextStyleData.offset = 0;
    bottomTextStyleData.uppercase = false;
    bottomTextStyleData.type = "Regular";

    mainTextStyleData.size = 26;
    mainTextStyleData.offset = 0;
    mainTextStyleData.uppercase = false;
    mainTextStyleData.type = "Regular";
}

