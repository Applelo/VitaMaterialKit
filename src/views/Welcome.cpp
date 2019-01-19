#include "Welcome.hh"


Welcome::Welcome(const char *name) : View(name) {
}

void Welcome::content() {
    //ui->texts->draw(0, 0, H1,  TEXT_PRIMARY, "test");
    ui->icons->draw(ICON_MDI_APPLE, 0,0, ICON_SECONDARY, DEFAULT_MATERIAL_ICON_SIZE);
}

