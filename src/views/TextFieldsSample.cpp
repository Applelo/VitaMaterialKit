#include "TextFieldsSample.hh"

TextFieldsSample::TextFieldsSample(const std::string &name) : View(name) {

}

void TextFieldsSample::contents() {
    textFieldFilledBasic = ui->textFields->filledDraw(
            0, 0, selector == 1, "Label",
            "Bonjour j'adore le fromage blanc avec du caramel même si antioconstitutionellement je ne peux pas en manger convenablement uouou.",
            TEXTFIELD_MODE_TEXTAREA ,
            TEXTFIELD_DEFAULT_WIDTH,
            0,
            THEME_PRIMARY,
            "Je suis là pour aider",
            "", //error
            ICON_MDI_CALENDAR, //leading icon
            "", //trailing icon
            "", //prefix text
            "", //suffix text
            TEXTFIELD_SP_INDICATOR,
            0);

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
