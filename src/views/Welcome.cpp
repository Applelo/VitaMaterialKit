#include "Welcome.hh"


Welcome::Welcome(const char *name) : View(name) {
    selector = -1;
}

void Welcome::contents() {
    ui->texts->draw(10, 10, Body1, TEXT_PRIMARY, "Choose a sample :");

    buttonsTZE = ui->buttons->containedDraw("Buttons", 10, 60, selector == 1, ICON_MDI_MOUSE);
    i18nTZE = ui->buttons->containedDraw("I18n", 10, 130, selector == 2,ICON_MDI_TRANSLATE);
    iconsTZE = ui->buttons->containedDraw("Icons", 10, 200, selector == 3, ICON_MDI_ICE_CREAM);
    textsTZE = ui->buttons->containedDraw("Texts", 10, 270, selector == 4, ICON_MDI_FORMAT_FONT);
    imeTZE = ui->buttons->containedDraw("IME", 10, 340, selector == 5, ICON_MDI_KEYBOARD);
    checkboxesTZE = ui->buttons->containedDraw("Checkboxes", 10, 410, selector == 6, ICON_MDI_CHECK);

    exitTZE = ui->buttons->containedDraw("Exit", 800, 480, selector == NUMBER_OF_BUTTONS);
}

void Welcome::controls() {


    //events
    if (ui->buttons->onTouch(buttonsTZE, utils->touch->lastClickPoint) ||
        ui->buttons->onPad(buttonsTZE, utils->pad->pressed.cross)) {
        viewsController->setActualView("ButtonsSample");
    }

    if (ui->buttons->onTouch(i18nTZE, utils->touch->lastClickPoint) ||
        ui->buttons->onPad(i18nTZE, utils->pad->pressed.cross)
    ) {
        viewsController->setActualView("I18nSample");
    }

    if (ui->buttons->onTouch(iconsTZE, utils->touch->lastClickPoint) ||
        ui->buttons->onPad(iconsTZE, utils->pad->pressed.cross)) {
        viewsController->setActualView("IconsSample");
    }

    if (ui->buttons->onTouch(textsTZE, utils->touch->lastClickPoint) ||
        ui->buttons->onPad(textsTZE, utils->pad->pressed.cross)) {
        viewsController->setActualView("TextsSample");
    }

    if (ui->buttons->onTouch(imeTZE, utils->touch->lastClickPoint) ||
        ui->buttons->onPad(imeTZE, utils->pad->pressed.cross)) {
        viewsController->setActualView("ImeSample");
    }

    if (ui->buttons->onTouch(checkboxesTZE, utils->touch->lastClickPoint) ||
        ui->buttons->onPad(checkboxesTZE, utils->pad->pressed.cross)) {
        viewsController->setActualView("CheckboxesSample");
    }

    if (ui->buttons->onTouch(exitTZE, utils->touch->lastClickPoint) ||
        ui->buttons->onPad(exitTZE, utils->pad->pressed.cross)) {
        viewsController->setActualView(VIEWS_CONTROLLER_EXIT);
    }

    //pad
    if (utils->pad->pressed.down) {
        selector++;
    }
    if (utils->pad->pressed.up) {
        selector--;
    }
    if (selector > NUMBER_OF_BUTTONS)
        selector = 1;
    if (selector == 0)
        selector = NUMBER_OF_BUTTONS;

    //touch & pad switch
    if (utils->touch->clicking) {
        selector = -1;
    }
    if (utils->pad->held.clicking && selector == -1) {
        selector = 1;
    }




}

