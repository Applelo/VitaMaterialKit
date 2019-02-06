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

//#region filledDraw


ZoneEventTextField UiTextFields::filledDraw(
        int x,
        int y,
        bool selector,
        std::string label,
        std::string text,
        TextFieldMode textFieldMode,
        int width,
        int height,
        TypeTheme typeTheme,
        std::string helperText,
        std::string errorText,
        const char *leadingIcon,
        const char *trailingIcon,
        std::string prefixText,
        std::string suffixText,
        TextFieldSuffixPosition suffixPosition,
        unsigned int charCounter
 ) {

    if (height == 0) {
        height = textFieldMode == TEXTFIELD_MODE_TEXTAREA ? TEXTFIELD_DEFAULT_TEXTAREA_HEIGHT : TEXTFIELD_DEFAULT_HEIGHT;
    }
    prefixIconPos = TEXTFIELD_PADDING;
    suffixIconPos = 0;
    prefixTextPos = 2;
    suffixTextPos = 2;


    //draw background
    vita2d_draw_rectangle(x, y, width, height, selector ? TEXTFIELD_BACKGROUND_FOCUS_COLOR : TEXTFIELD_BACKGROUND_NOFOCUS_COLOR);

    //draw bar status
    if (errorText.length() > 0) {
        vita2d_draw_rectangle(x, y + (height - TEXTFIELD_FOCUSBAR_SIZE), width, TEXTFIELD_FOCUSBAR_SIZE, TEXTFIELD_ERROR_COLOR);
    }
    else if (selector) {
        vita2d_draw_rectangle(x, y + (height - TEXTFIELD_FOCUSBAR_SIZE), width, TEXTFIELD_FOCUSBAR_SIZE, typeTheme == THEME_PRIMARY ? theme->getPrimaryRGBA().normal : theme->getSecondaryRGBA().normal);
    }
    else {
        vita2d_draw_rectangle(x, y + (height - TEXTFIELD_NOFOCUSBAR_SIZE), width, TEXTFIELD_NOFOCUSBAR_SIZE, TEXTFIELD_NOFOCUSBAR_COLOR);
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
        icons->draw(trailingIcon, x + width - TEXTFIELD_PADDING - TEXTFIELD_ICONS_SIZE, y + 20, TEXTFIELD_HELPER_COLOR, TEXTFIELD_ICONS_SIZE);
        zoneEventTextField.leadingIcon.x = x + width - TEXTFIELD_PADDING - TEXTFIELD_ICONS_SIZE;
        zoneEventTextField.leadingIcon.y = y + 20;
        zoneEventTextField.leadingIcon.width = width;
        zoneEventTextField.leadingIcon.height = height;

        suffixIconPos = TEXTFIELD_ICONS_SIZE + TEXTFIELD_PADDING;
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
        suffixTextPos = width - textDataText.width - TEXTFIELD_PADDING;
        texts->draw(x + suffixTextPos, y + 30, mainTextStyleData, TEXTFIELD_HELPER_COLOR, suffixText);
    }

    //adjust text
    if (text.length() > 0) {
        textDataText = texts->getTextData(text, mainTextStyleData);

        //adjust showed text
        if (textFieldMode == TEXTFIELD_MODE_SINGLE && textDataText.width > (width - TEXTFIELD_PADDING - prefixIconPos - suffixIconPos)) {
            showedText = text.substr(textDataText.width / (mainTextStyleData.size - 10), text.size());
        }
        else if (textFieldMode == TEXTFIELD_MODE_MULTI && textDataText.width > (width - TEXTFIELD_PADDING - prefixIconPos - suffixIconPos)) {
            height = TEXTFIELD_DEFAULT_HEIGHT * keySearch(showedText, "\n");
            showedText = this->applyTextWidthLimit(text, width);
            showedText = this->applyTextHeightLimit(showedText, height);
        }
        else if (textFieldMode == TEXTFIELD_MODE_TEXTAREA && textDataText.width > (width - TEXTFIELD_PADDING - prefixIconPos - suffixIconPos)) {
            showedText = this->applyTextWidthLimit(text, width);
            showedText = this->applyTextHeightLimit(showedText, height);
        }
        else {
            showedText = text;
        }
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
            texts->draw(x + suffixTextPos - textDataText.width - 4, y + 30, mainTextStyleData, showedText);
        }
        else {
            texts->draw(x + prefixIconPos + prefixTextPos, y + 30, mainTextStyleData, showedText);
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
        texts->draw(x + prefixIconPos, y + height + 2, bottomTextStyleData, TEXTFIELD_ERROR_COLOR, errorText);
    }
    else if (helperText.length() > 0) {
        texts->draw(x + prefixIconPos, y + height + 2, bottomTextStyleData, TEXTFIELD_HELPER_COLOR, helperText);
    }

    //draw char counter
    if (charCounter > 0) {
        charCounterText = std::to_string(text.length()) + "/" + std::to_string(charCounter);
        textDataText = texts->getTextData(charCounterText, bottomTextStyleData);
        texts->draw(x + width - TEXTFIELD_PADDING - textDataText.width, y + height, bottomTextStyleData, TEXTFIELD_HELPER_COLOR, charCounterText);
    }


    //vita2d_draw_rectangle(x + prefixIconPos, y, width - TEXTFIELD_PADDING - prefixIconPos - suffixIconPos, height, RGBA8(255, 0, 0, 150));


    zoneEventTextField.x = x + prefixIconPos;
    zoneEventTextField.y = y;
    zoneEventTextField.width = width - TEXTFIELD_PADDING - prefixIconPos - suffixIconPos;
    zoneEventTextField.height = height;
    zoneEventTextField.selector = selector;

    return zoneEventTextField;
}

//#region single

ZoneEventTextField UiTextFields::filledDrawSingle(int x, int y, bool selector, std::string label, std::string text, std::string helper, std::string error, TypeTheme typeTheme) {
    return this->filledDraw(
            x,
            y,
            selector,
            std::move(label),
            std::move(text),
            TEXTFIELD_MODE_SINGLE,
            TEXTFIELD_DEFAULT_WIDTH,
            0,
            typeTheme,
            std::move(helper),
            std::move(error)
            );
}

ZoneEventTextField UiTextFields::filledDrawSingle(int x, int y, int width, bool selector, std::string label, std::string text, std::string helper, std::string error, TypeTheme typeTheme) {
    return this->filledDraw(
            x,
            y,
            selector,
            std::move(label),
            std::move(text),
            TEXTFIELD_MODE_SINGLE,
            width,
            0,
            typeTheme,
            std::move(helper),
            std::move(error)
    );
}

ZoneEventTextField UiTextFields::filledDrawSingle(int x, int y, int width, int height, bool selector, std::string label, std::string text, std::string helper, std::string error, TypeTheme typeTheme) {
    return this->filledDraw(
            x,
            y,
            selector,
            std::move(label),
            std::move(text),
            TEXTFIELD_MODE_SINGLE,
            width,
            height,
            typeTheme,
            std::move(helper),
            std::move(error)
    );
}

//#endregion

//#region multi

ZoneEventTextField UiTextFields::filledDrawMulti(int x, int y, bool selector, std::string label, std::string text, std::string helper, std::string error, TypeTheme typeTheme) {
    return this->filledDraw(
            x,
            y,
            selector,
            std::move(label),
            std::move(text),
            TEXTFIELD_MODE_MULTI,
            TEXTFIELD_DEFAULT_WIDTH,
            0,
            typeTheme,
            std::move(helper),
            std::move(error)
    );
}

ZoneEventTextField UiTextFields::filledDrawMulti(int x, int y, int width, bool selector, std::string label, std::string text, std::string helper, std::string error, TypeTheme typeTheme) {
    return this->filledDraw(
            x,
            y,
            selector,
            std::move(label),
            std::move(text),
            TEXTFIELD_MODE_MULTI,
            width,
            0,
            typeTheme,
            std::move(helper),
            std::move(error)
    );
}

ZoneEventTextField UiTextFields::filledDrawMulti(int x, int y, int width, int height, bool selector, std::string label, std::string text, std::string helper, std::string error, TypeTheme typeTheme) {
    return this->filledDraw(
            x,
            y,
            selector,
            std::move(label),
            std::move(text),
            TEXTFIELD_MODE_MULTI,
            width,
            height,
            typeTheme,
            std::move(helper),
            std::move(error)
    );
}
//#endregion

//#region textarea

ZoneEventTextField UiTextFields::filledDrawTextArea(int x, int y, bool selector, std::string label, std::string text, std::string helper, std::string error, TypeTheme typeTheme) {
    return this->filledDraw(
            x,
            y,
            selector,
            std::move(label),
            std::move(text),
            TEXTFIELD_MODE_TEXTAREA,
            TEXTFIELD_DEFAULT_WIDTH,
            0,
            typeTheme,
            std::move(helper),
            std::move(error)
    );
}

ZoneEventTextField UiTextFields::filledDrawTextArea(int x, int y, int width, bool selector, std::string label, std::string text, std::string helper, std::string error, TypeTheme typeTheme) {
    return this->filledDraw(
            x,
            y,
            selector,
            std::move(label),
            std::move(text),
            TEXTFIELD_MODE_TEXTAREA,
            width,
            0,
            typeTheme,
            std::move(helper),
            std::move(error)
    );
}

ZoneEventTextField UiTextFields::filledDrawTextArea(int x, int y, int width, int height, bool selector, std::string label, std::string text, std::string helper, std::string error, TypeTheme typeTheme) {
    return this->filledDraw(
            x,
            y,
            selector,
            std::move(label),
            std::move(text),
            TEXTFIELD_MODE_TEXTAREA,
            width,
            height,
            typeTheme,
            std::move(helper),
            std::move(error)
    );
}
//#endregion

//#endregion

//#region utils

int UiTextFields::keySearch(const std::string& s, const std::string& key) {
    int count = 0;
    size_t pos=0;
    while ((pos = s.find(key, pos)) != std::string::npos) {
        ++count;
        ++pos;
    }
    return count;
}

std::string UiTextFields::applyTextWidthLimit(std::string text, int width) {
    textDataText = texts->getTextData(text, mainTextStyleData);

    if (textDataText.width > (width - TEXTFIELD_PADDING - prefixIconPos - suffixIconPos)) {

        posBreak = (unsigned int) (this->keySearch(text, "\n") + 1);
        posBreak = posBreak * (width - TEXTFIELD_PADDING - prefixIconPos - suffixIconPos);
        posBreak = posBreak / (mainTextStyleData.size / 2);

        std::string::size_type lastFound = text.find_last_of('\n');
        std::string::size_type found = text.find(' ', posBreak);

        if (lastFound == std::string::npos) {
            lastFound = 0;
        }

        if (found == std::string::npos) {
            found = text.length() - 1;
        }

        if ((found - lastFound) > 28) {
            text.insert(posBreak, "-\n");
        }
        else {
            text.replace(found, 1, "\n");
        }

        return this->applyTextWidthLimit(text, width);
    }

    return text;
}

std::string UiTextFields::applyTextHeightLimit(std::string text, int height) {
    textDataText = texts->getTextData(text, mainTextStyleData);

    if (textDataText.height > (height - 32)) {
        std::string::size_type found = text.find_first_of('\n');

        if (found != std::string::npos) {
            text = text.substr(found + 1, text.length() - 1);
            return this->applyTextHeightLimit(text, height);
        }
    }

    return text;
}


//#endregion

