#include "IconsSample.hh"

IconsSample::IconsSample(const std::string &name) : View(name) {
}

void IconsSample::contents() {
    ui->icons->draw(ICON_MDI_ACCOUNT, 10, 10);
    ui->icons->draw(ICON_MDI_STAR, 10, 60);
    ui->icons->draw(ICON_MDI_MICROSOFT, 10, 100, (unsigned int) RGBA8(255, 255, 0, 255));
    ui->icons->draw(ICON_MDI_APPLE, 10, 140, THEME_PRIMARY, 100);
    ui->icons->drawPSVita(ICON_PSVITA_PLAYSTATION, 10, 260, THEME_PRIMARY, 1.5f);

    back = ui->buttons->containedDraw("Back", 800, 480);
}

void IconsSample::controls() {
    if (EventUi::onTouch(back, utils->touch->lastClickPoint)||
            EventUi::onPad(back, utils->pad->pressed.cross) ||
        utils->pad->pressed.circle
            ) {
        viewsController->setActualView("Welcome");
    }
}
