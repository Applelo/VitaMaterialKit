#include "Welcome.hh"


Welcome::Welcome(const char *name) : View(name) {
}

void Welcome::contents() {
    ui->texts->draw(0, 0, H1,  TEXT_PRIMARY, "Welcome");
    touchZoneEvent = ui->buttons->floatDraw(ICON_MDI_PLUS, 300, 450, "Go Buttons sample");
}

void Welcome::controls() {
    if (ui->buttons->onTouch(touchZoneEvent, utils->touch->lastClickPoint)) {
        viewsController->setActualView("ButtonsSample");
    }
}

