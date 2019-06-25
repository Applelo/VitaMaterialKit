#include "I18nSample.hh"


I18nSample::I18nSample(const char *name) : View(name) {
}

void I18nSample::contents() {

    ui->texts->draw(10, 10, Body1, THEME_PRIMARY, defaultL["phrase"]);
    ui->texts->draw(10, 60, Body1, THEME_PRIMARY, frL["phrase"]);
    ui->texts->draw(10, 110, Body1, THEME_PRIMARY, enL["phrase"]);

    back = ui->buttons->containedDraw("Back", 800, 480);
}

void I18nSample::controls() {
    if (EventUi::onTouch(back, utils->touch->lastClickPoint)||
            EventUi::onPad(back, utils->pad->pressed.cross) ||
        utils->pad->pressed.circle
            ) {
        viewsController->setActualView("Welcome");
    }
}

void I18nSample::mounted() {
    UtilsI18n *frLang = new UtilsI18n(SCE_SYSTEM_PARAM_LANG_FRENCH);
    UtilsI18n *enLang = new UtilsI18n(SCE_SYSTEM_PARAM_LANG_ENGLISH_US);

    defaultL = utils->i18n->getI18nByCat("test");
    frL = frLang->getI18nByCat("test");
    enL = enLang->getI18nByCat("test");
}

