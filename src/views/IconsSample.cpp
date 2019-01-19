#include "IconsSample.hh"

IconsSample::IconsSample(const std::string &name) : View(name) {
}

void IconsSample::contents() {
    ui->icons->draw(ICON_MDI_ACCOUNT, 10, 10);
    ui->icons->draw(ICON_MDI_STAR, 10, 60);
    ui->icons->draw(ICON_MDI_MICROSOFT, 10, 100, (unsigned int) RGBA8(255, 255, 0, 255));
    ui->icons->draw(ICON_MDI_APPLE, 10, 140, ICON_PRIMARY, 100);

    back = ui->buttons->containedDraw("Back", 800, 480);
}

void IconsSample::controls() {
    if (ui->buttons->onTouch(back, utils->touch->lastClickPoint)) {
        viewsController->setActualView("Welcome");
    }
}
