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
        TextFieldSuffixPosition suffixPosition,
        int charCounter
 ) {

    prefixIconPos = TEXTFIELD_PADDING;
    prefixTextPos = 2;
    suffixTextPos = 2;


    //draw background
    vita2d_draw_rectangle(x, y, TEXTFIELD_WIDTH, TEXTFIELD_HEIGTH, selector ? TEXTFIELD_BACKGROUND_FOCUS_COLOR : TEXTFIELD_BACKGROUND_NOFOCUS_COLOR);

    //draw bar status
    if (errorText.length() > 0) {
        vita2d_draw_rectangle(x, y + (TEXTFIELD_HEIGTH - TEXTFIELD_FOCUSBAR_SIZE), TEXTFIELD_WIDTH, TEXTFIELD_FOCUSBAR_SIZE, TEXTFIELD_ERROR_COLOR);
    }
    else if (selector) {
        vita2d_draw_rectangle(x, y + (TEXTFIELD_HEIGTH - TEXTFIELD_FOCUSBAR_SIZE), TEXTFIELD_WIDTH, TEXTFIELD_FOCUSBAR_SIZE, typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().normal : theme->getSecondaryRGBA().normal);
    }
    else {
        vita2d_draw_rectangle(x, y + (TEXTFIELD_HEIGTH - TEXTFIELD_NOFOCUSBAR_SIZE), TEXTFIELD_WIDTH, TEXTFIELD_NOFOCUSBAR_SIZE, TEXTFIELD_NOFOCUSBAR_COLOR);
    }

    //prefixIcon
    if (strlen(leadingIcon) > 0) {
        icons->draw(leadingIcon, x + TEXTFIELD_PADDING, y + 20, TEXTFIELD_HELPER_COLOR, TEXTFIELD_ICONS_SIZE);
        prefixIconPos += TEXTFIELD_ICONS_SIZE + TEXTFIELD_PADDING;
        zoneEventTextField.leadingIcon.x = x + TEXTFIELD_PADDING;
        zoneEventTextField.leadingIcon.y = y + 20;
        zoneEventTextField.leadingIcon.width = TEXTFIELD_ICONS_SIZE;
        zoneEventTextField.leadingIcon.height = TEXTFIELD_ICONS_SIZE;
    }
    else {
        zoneEventTextField.leadingIcon.x = 0;
        zoneEventTextField.leadingIcon.y = 0;
        zoneEventTextField.leadingIcon.width = 0;
        zoneEventTextField.leadingIcon.height = 0;
    }
    zoneEventTextField.leadingIcon.selector = false;

    //suffixIcon
    if (strlen(trailingIcon) > 0) {
        icons->draw(trailingIcon, x + TEXTFIELD_WIDTH - TEXTFIELD_PADDING - TEXTFIELD_ICONS_SIZE, y + 20, TEXTFIELD_HELPER_COLOR, TEXTFIELD_ICONS_SIZE);
        zoneEventTextField.leadingIcon.x = x + TEXTFIELD_WIDTH - TEXTFIELD_PADDING - TEXTFIELD_ICONS_SIZE;
        zoneEventTextField.leadingIcon.y = y + 20;
        zoneEventTextField.leadingIcon.width = TEXTFIELD_WIDTH;
        zoneEventTextField.leadingIcon.height = TEXTFIELD_HEIGTH;
    }
    else {
        zoneEventTextField.leadingIcon.x = 0;
        zoneEventTextField.leadingIcon.y = 0;
        zoneEventTextField.leadingIcon.width = 0;
        zoneEventTextField.leadingIcon.height = 0;
    }
    zoneEventTextField.trailingIcon.selector = false;

    //prefix
    if (prefixText.length() > 0) {
        textDataText = texts->getTextData(prefixText, mainTextStyleData);
        texts->draw(x + prefixIconPos, y + 30, mainTextStyleData, TEXTFIELD_HELPER_COLOR, prefixText);
        prefixTextPos += textDataText.width;
    }

    //suffix
    if (suffixText.length() > 0) {
        textDataText = texts->getTextData(suffixText, mainTextStyleData);
        suffixTextPos = TEXTFIELD_WIDTH - textDataText.width - TEXTFIELD_PADDING;
        texts->draw(x + suffixTextPos, y + 30, mainTextStyleData, TEXTFIELD_HELPER_COLOR, suffixText);
    }


    if (text.length() > 0) {

        //label
        if (selector) {
            texts->draw(x + prefixIconPos, y + 4, bottomTextStyleData, typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().normal : theme->getSecondaryRGBA().normal, std::move(label));
        }
        else {
            texts->draw(x + prefixIconPos, y + 4, bottomTextStyleData, std::move(label));
        }

        //text
        if (suffixText.length() > 0 && suffixPosition == TEXTFIELD_SP_STICK) {//suffix case
            textDataText = texts->getTextData(text, mainTextStyleData);
            texts->draw(x + suffixTextPos - textDataText.width - 4, y + 30, mainTextStyleData, text);
        }
        else {
            texts->draw(x + prefixIconPos + prefixTextPos, y + 30, mainTextStyleData, text);
        }

    }
    else {
        //label
        if (selector) {
            texts->draw(x + prefixIconPos, y + 4, bottomTextStyleData, typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().normal : theme->getSecondaryRGBA().normal, std::move(label));
        }
        else {
            texts->draw(x + prefixIconPos, y + 26, Body1, errorText.length() > 0 ? TEXTFIELD_ERROR_COLOR : (typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().normal : theme->getSecondaryRGBA().normal), std::move(label));
        }
    }


    //draw helper
    if (errorText.length() > 0) {
        texts->draw(x + prefixIconPos, y + TEXTFIELD_HEIGTH + 2, bottomTextStyleData, TEXTFIELD_ERROR_COLOR, errorText);
    }
    else if (helperText.length() > 0) {
        texts->draw(x + prefixIconPos, y + TEXTFIELD_HEIGTH + 2, bottomTextStyleData, TEXTFIELD_HELPER_COLOR, helperText);
    }

    //draw char counter
    if (charCounter > 0) {
        charCounterText = std::to_string(text.length()) + "/" + std::to_string(charCounter);
        textDataText = texts->getTextData(charCounterText, bottomTextStyleData);
        texts->draw(x + TEXTFIELD_WIDTH - TEXTFIELD_PADDING - textDataText.width, y + TEXTFIELD_HEIGTH, bottomTextStyleData, TEXTFIELD_HELPER_COLOR, charCounterText);
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

