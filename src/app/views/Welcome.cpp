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
    if (EventUi::onTouch(buttonsTZE, utils->touch->lastClickPoint) ||
            EventUi::onPad(buttonsTZE, utils->pad->pressed.cross)) {
        viewsController->setActualView("ButtonsSample");
    }

    if (EventUi::onTouch(i18nTZE, utils->touch->lastClickPoint) ||
            EventUi::onPad(i18nTZE, utils->pad->pressed.cross)
    ) {
        viewsController->setActualView("I18nSample");
    }

    if (EventUi::onTouch(iconsTZE, utils->touch->lastClickPoint) ||
            EventUi::onPad(iconsTZE, utils->pad->pressed.cross)) {
        viewsController->setActualView("IconsSample");
    }

    if (EventUi::onTouch(textsTZE, utils->touch->lastClickPoint) ||
            EventUi::onPad(textsTZE, utils->pad->pressed.cross)) {
        viewsController->setActualView("TextsSample");
    }

    if (EventUi::onTouch(checkboxesTZE, utils->touch->lastClickPoint) ||
            EventUi::onPad(checkboxesTZE, utils->pad->pressed.cross)) {
        viewsController->setActualView("CheckboxesSample");
    }

    if (EventUi::onTouch(textfieldsTZE, utils->touch->lastClickPoint) ||
            EventUi::onPad(textfieldsTZE, utils->pad->pressed.cross)) {
        viewsController->setActualView("TextFieldsSample");
    }

    if (EventUi::onTouch(cardsTZE, utils->touch->lastClickPoint) ||
            EventUi::onPad(cardsTZE, utils->pad->pressed.cross)) {
        viewsController->setActualView("CardsSample");
    }

    if (EventUi::onTouch(exitTZE, utils->touch->lastClickPoint) ||
            EventUi::onPad(exitTZE, utils->pad->pressed.cross)) {
        viewsController->setActualView(VIEWS_CONTROLLER_EXIT);
    }

}

void Welcome::beforeEnter() {
    this->utils->PTC->setLimit(2, 7);
}

int Welcome::getXMenuItemPosition(int item) {
    return (item * 60) + ((item - 1) * 10);
}

