#include "TextFieldsSample.hh"

TextFieldsSample::TextFieldsSample(const std::string &name) : View(name) {
    ime = new IME();
}

void TextFieldsSample::contents() {

    singleLeadingIconEvent = ui->textFields->filledDrawLeadingIcon(10, 10, TEXTFIELD_MODE_SINGLE, selector == 1, "Leading Icon", ICON_MDI_CALENDAR, singleLeadingIcon);
    singleTrailingIconEvent = ui->textFields->filledDrawTrailingIcon(10, 20 + TEXTFIELD_DEFAULT_HEIGHT, TEXTFIELD_MODE_SINGLE, selector == 2, "Trailing Icon", singleTrailingIcon, ICON_MDI_SWORD_CROSS);
    singlePrefixTextEvent = ui->textFields->filledDrawPrefixText(10, 30 + (TEXTFIELD_DEFAULT_HEIGHT * 2), TEXTFIELD_MODE_SINGLE, selector == 3, "Prefix Text", "$", singlePrefixText);
    singleSuffixTextEvent = ui->textFields->filledDrawSuffixText(10, 40 + (TEXTFIELD_DEFAULT_HEIGHT * 3), TEXTFIELD_MODE_SINGLE, selector == 4, "Suffix Text", singleSuffixText, "/100", TEXTFIELD_SP_STICK, "Helping");

    textareaEvent = ui->textFields->filledDraw(20 + TEXTFIELD_DEFAULT_WIDTH, 10, TEXTFIELD_MODE_TEXTAREA, selector == (NUMBER_OF_BUTTONS_TEXTFIELDS - 2), "TextField TextArea", textarea);
    multipleEvent = ui->textFields->filledDraw(20 + TEXTFIELD_DEFAULT_WIDTH, 40 + (TEXTFIELD_DEFAULT_HEIGHT * 3), TEXTFIELD_MODE_MULTI, selector == (NUMBER_OF_BUTTONS_TEXTFIELDS - 1), "TextField Multiple", multiple, "", "Error", 40);

    back = ui->buttons->containedDraw("Back", 800, 480, THEME_PRIMARY, selector == NUMBER_OF_BUTTONS_TEXTFIELDS);
}

void TextFieldsSample::controls() {
    //pad
    if (utils->pad->pressed.down) {
        selector++;
    }
    if (utils->pad->pressed.up) {
        selector--;
    }
    if (selector > NUMBER_OF_BUTTONS_TEXTFIELDS)
        selector = 1;
    if (selector == 0)
        selector = NUMBER_OF_BUTTONS_TEXTFIELDS;

    //touch & pad switch
    if (utils->touch->clicking) {
        selector = -1;
    }
    if (utils->pad->held.clicking && selector == -1) {
        selector = 1;
    }

    if (ui->textFields->onTouch(singleLeadingIconEvent, utils->touch->lastClickPoint) ||
        ui->textFields->onPad(singleLeadingIconEvent, utils->pad->pressed.cross)) {
        singleLeadingIcon = ime->getUserText("Text", singleLeadingIcon.c_str());
    }

    if (ui->textFields->onTouch(singleTrailingIconEvent, utils->touch->lastClickPoint) ||
        ui->textFields->onPad(singleTrailingIconEvent, utils->pad->pressed.cross)) {
        singleTrailingIcon = ime->getUserText("Text", singleTrailingIcon.c_str());
    }

    if (ui->textFields->onTouch(singlePrefixTextEvent, utils->touch->lastClickPoint) ||
        ui->textFields->onPad(singlePrefixTextEvent, utils->pad->pressed.cross)) {
        singlePrefixText = ime->getUserText("Text", singlePrefixText.c_str());
    }

    if (ui->textFields->onTouch(singleSuffixTextEvent, utils->touch->lastClickPoint) ||
        ui->textFields->onPad(singleSuffixTextEvent, utils->pad->pressed.cross)) {
        singleSuffixText = ime->getUserText("Text", singleSuffixText.c_str());
    }

    if (ui->textFields->onTouch(textareaEvent, utils->touch->lastClickPoint) ||
        ui->textFields->onPad(textareaEvent, utils->pad->pressed.cross)) {
        textarea = ime->getUserText("Text", textarea.c_str());
    }

    if (ui->textFields->onTouch(multipleEvent, utils->touch->lastClickPoint) ||
        ui->textFields->onPad(multipleEvent, utils->pad->pressed.cross)) {
        multiple = ime->getUserText("Text", multiple.c_str());
    }

    if (ui->buttons->onTouch(back, utils->touch->lastClickPoint) ||
        ui->buttons->onPad(back, utils->pad->pressed.cross) ||
        utils->pad->pressed.circle) {

        viewsController->setActualView("Welcome");
    }
}
