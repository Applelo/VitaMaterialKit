#include "Welcome.hh"


Welcome::Welcome(const char *name) : View(name) {
}

void Welcome::contents() {
    ui->texts->draw(10, 10, Body1, THEME_PRIMARY, "Choose a sample :");

    buttonsTZE = ui->buttons->containedDraw("Buttons", 10, getXMenuItemPosition(1), THEME_PRIMARY, utils->PTC->isXY(PADTOUCHCTRL_IS_FIRST, PADTOUCHCTRL_IS_FIRST), ICON_MDI_MOUSE);
    i18nTZE = ui->buttons->containedDraw("I18n", 10, getXMenuItemPosition(2), THEME_PRIMARY, utils->PTC->isXY(PADTOUCHCTRL_IS_FIRST, 2),ICON_MDI_TRANSLATE);
    iconsTZE = ui->buttons->containedDraw("Icons", 10, getXMenuItemPosition(3), THEME_PRIMARY, utils->PTC->isXY(PADTOUCHCTRL_IS_FIRST, 3), ICON_MDI_ICE_CREAM);
    textsTZE = ui->buttons->containedDraw("Texts", 10, getXMenuItemPosition(4), THEME_PRIMARY, utils->PTC->isXY(PADTOUCHCTRL_IS_FIRST, 4), ICON_MDI_FORMAT_FONT);
    checkboxesTZE = ui->buttons->containedDraw("Checkboxes & Radio Boxes", 10, getXMenuItemPosition(5), THEME_PRIMARY, utils->PTC->isXY(PADTOUCHCTRL_IS_FIRST, 5), ICON_MDI_CHECK);
    textfieldsTZE = ui->buttons->containedDraw("TextFields", 10, getXMenuItemPosition(6), THEME_PRIMARY, utils->PTC->isXY(PADTOUCHCTRL_IS_FIRST, 6), ICON_MDI_KEYBOARD);
    cardsTZE = ui->buttons->containedDraw("Cards", 10, getXMenuItemPosition(7), THEME_PRIMARY, utils->PTC->isXY(PADTOUCHCTRL_IS_FIRST, 7), ICON_MDI_KEYBOARD);

    exitTZE = ui->buttons->containedDraw("Exit", 800, getXMenuItemPosition(7), THEME_PRIMARY, utils->PTC->isX(2));
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

    if (ui->buttons->onTouch(checkboxesTZE, utils->touch->lastClickPoint) ||
        ui->buttons->onPad(checkboxesTZE, utils->pad->pressed.cross)) {
        viewsController->setActualView("CheckboxesSample");
    }

    if (ui->buttons->onTouch(textfieldsTZE, utils->touch->lastClickPoint) ||
        ui->buttons->onPad(textfieldsTZE, utils->pad->pressed.cross)) {
        viewsController->setActualView("TextFieldsSample");
    }

    if (ui->buttons->onTouch(cardsTZE, utils->touch->lastClickPoint) ||
        ui->buttons->onPad(cardsTZE, utils->pad->pressed.cross)) {
        viewsController->setActualView("CardsSample");
    }

    if (ui->buttons->onTouch(exitTZE, utils->touch->lastClickPoint) ||
        ui->buttons->onPad(exitTZE, utils->pad->pressed.cross)) {
        viewsController->setActualView(VIEWS_CONTROLLER_EXIT);
    }

}

void Welcome::beforeEnter() {
    this->utils->PTC->setLimit(2, 7);
}

int Welcome::getXMenuItemPosition(int item) {
    return (item * 60) + ((item - 1) * 10);
}

