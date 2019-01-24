#include "TextFieldsSample.hh"

TextFieldsSample::TextFieldsSample(const std::string &name) : View(name) {

}

void TextFieldsSample::contents() {
    textFieldFilledBasic = ui->textFields->filledDraw(0, 0, selector == 1, "Label", "Test", THEME_PRIMARY, "Je suis là pour aider", "", ICON_MDI_CALENDAR, "", "$");

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


    if (ui->buttons->onTouch(back, utils->touch->lastClickPoint) ||
        ui->buttons->onPad(back, utils->pad->pressed.cross) ||
        utils->pad->pressed.circle) {

        viewsController->setActualView("Welcome");
    }
}
