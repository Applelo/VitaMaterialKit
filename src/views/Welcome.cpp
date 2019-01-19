#include "Welcome.hh"


Welcome::Welcome(const char *name) : View(name) {
}

void Welcome::contents() {
    ui->texts->draw(10, 10, Body1, TEXT_PRIMARY, "Choose a sample :");

    buttonsTZE = ui->buttons->containedDraw("Buttons", 10, 60, ICON_MDI_MOUSE);
    i18nTZE = ui->buttons->containedDraw("I18n", 10, 130, ICON_MDI_TRANSLATE);
}

void Welcome::controls() {
    if (ui->buttons->onTouch(buttonsTZE, utils->touch->lastClickPoint)) {
        viewsController->setActualView("ButtonsSample");
    }

    if (ui->buttons->onTouch(i18nTZE, utils->touch->lastClickPoint)) {
        viewsController->setActualView("I18nSample");
    }
}

