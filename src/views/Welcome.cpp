#include "Welcome.hh"


Welcome::Welcome(const char *name) : View(name) {
}

void Welcome::contents() {
    ui->texts->draw(10, 10, Body1, TEXT_PRIMARY, "Choose a sample :");

    buttonsTZE = ui->buttons->containedDraw("Buttons", 10, 60, ICON_MDI_MOUSE);
    i18nTZE = ui->buttons->containedDraw("I18n", 10, 130, ICON_MDI_TRANSLATE);
    iconsTZE = ui->buttons->containedDraw("Icons", 10, 200, ICON_MDI_ICE_CREAM);


    exitTZE = ui->buttons->containedDraw("Exit", 800, 480);
}

void Welcome::controls() {
    if (ui->buttons->onTouch(buttonsTZE, utils->touch->lastClickPoint)) {
        viewsController->setActualView("ButtonsSample");
    }

    if (ui->buttons->onTouch(i18nTZE, utils->touch->lastClickPoint)) {
        viewsController->setActualView("I18nSample");
    }

    if (ui->buttons->onTouch(iconsTZE, utils->touch->lastClickPoint)) {
        viewsController->setActualView("IconsSample");
    }

    if (ui->buttons->onTouch(exitTZE, utils->touch->lastClickPoint)) {
        viewsController->setActualView(VIEWS_CONTROLLER_EXIT);
    }
}

