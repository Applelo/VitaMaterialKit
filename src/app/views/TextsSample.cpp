#include "TextsSample.hh"

TextsSample::TextsSample(const std::string &name) : View(name) {}


void TextsSample::contents() {
    ui->texts->draw(0, 0, H1, THEME_PRIMARY, "H1");
    ui->texts->draw(0, 70, H2, THEME_PRIMARY, "H2");
    ui->texts->draw(0, 140, H3, THEME_PRIMARY, "H3");
    ui->texts->draw(0, 210, H4, THEME_PRIMARY, "H4");
    ui->texts->draw(0, 280, H5, THEME_PRIMARY, "H5");
    ui->texts->draw(0, 350, H6, THEME_PRIMARY, "H6");
    ui->texts->draw(0, 420, Sub1, THEME_PRIMARY, "Sub1");
    ui->texts->draw(0, 490, Sub2, THEME_PRIMARY, "Sub2");

    ui->texts->draw(200, 0, H1, THEME_PRIMARY, true, "H1");
    ui->texts->draw(200, 70, H2, THEME_PRIMARY, true, "H2");
    ui->texts->draw(200, 140, H3, THEME_PRIMARY, true, "H3");
    ui->texts->draw(200, 210, H4, THEME_PRIMARY, true, "H4");
    ui->texts->draw(200, 280, H5, THEME_PRIMARY, true, "H5");
    ui->texts->draw(200, 350, H6, THEME_PRIMARY, true, "H6");
    ui->texts->draw(200, 420, Sub1, THEME_PRIMARY, "Sub1");
    ui->texts->draw(200, 490, Sub2, THEME_PRIMARY, "Sub2");
    

    back = ui->buttons->containedDraw("Back", 800, 480);
}

void TextsSample::controls() {
    if (EventUi::onTouch(back, utils->touch->lastClickPoint)||
            EventUi::onPad(back, utils->pad->pressed.cross) ||
        utils->pad->pressed.circle
            ) {
        viewsController->setActualView("Welcome");
    }
}
