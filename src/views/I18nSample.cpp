#include "I18nSample.hh"


I18nSample::I18nSample(const char *name) : View(name) {
}

void I18nSample::contents() {

    ui->texts->draw(0, 140, Body1, TEXT_PRIMARY, utils->i18n->getI18nByCat("test")["phrase"]);
    ui->texts->draw(0, 210, Body1, TEXT_PRIMARY, frLang->getI18nByCat("test")["phrase"]);
    ui->texts->draw(0, 280, Body1, TEXT_PRIMARY, enLang->getI18nByCat("test")["phrase"]);

    back = ui->buttons->containedDraw("Back", 800, 480);
}

void I18nSample::controls() {
    if (ui->buttons->onTouch(back, utils->touch->lastClickPoint)) {
        viewsController->setActualView("Welcome");
    }
}

