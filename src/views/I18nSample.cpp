#include "I18nSample.hh"


I18nSample::I18nSample(const char *name) : View(name) {
}

void I18nSample::contents() {

    //ui->texts->draw(10, 10, Body1, THEME_PRIMARY, utils->i18n->getI18nByCat("test")["phrase"]);
    ui->texts->draw(10, 60, Body1, THEME_PRIMARY, frLang->getI18nByCat("test")["phrase"]);
    ui->texts->draw(10, 110, Body1, THEME_PRIMARY, enLang->getI18nByCat("test")["phrase"]);

    back = ui->buttons->containedDraw("Back", 800, 480);
}

void I18nSample::controls() {
    if (ui->buttons->onTouch(back, utils->touch->lastClickPoint)) {
        viewsController->setActualView("Welcome");
    }
}

