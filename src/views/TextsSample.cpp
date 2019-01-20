#include "TextsSample.hh"

TextsSample::TextsSample(const std::string &name) : View(name) {}


void TextsSample::contents() {
    ui->texts->draw(0, 0, H1, TEXT_PRIMARY, "H1");
    ui->texts->draw(0, 70, H2, TEXT_PRIMARY, "H2");
    ui->texts->draw(0, 140, H3, TEXT_PRIMARY, "H3");
    ui->texts->draw(0, 210, H4, TEXT_PRIMARY, "H4");
    ui->texts->draw(0, 280, H5, TEXT_PRIMARY, "H5");
    ui->texts->draw(0, 350, H6, TEXT_PRIMARY, "H6");
    ui->texts->draw(0, 420, Sub1, TEXT_PRIMARY, "Sub1");
    ui->texts->draw(0, 490, Sub2, TEXT_PRIMARY, "Sub2");

    ui->texts->draw(200, 0, H1, TEXT_PRIMARY, true, "H1");
    ui->texts->draw(200, 70, H2, TEXT_PRIMARY, true, "H2");
    ui->texts->draw(200, 140, H3, TEXT_PRIMARY, true, "H3");
    ui->texts->draw(200, 210, H4, TEXT_PRIMARY, true, "H4");
    ui->texts->draw(200, 280, H5, TEXT_PRIMARY, true, "H5");
    ui->texts->draw(200, 350, H6, TEXT_PRIMARY, true, "H6");
    ui->texts->draw(200, 420, Sub1, TEXT_PRIMARY, "Sub1");
    ui->texts->draw(200, 490, Sub2, TEXT_PRIMARY, "Sub2");
    

    back = ui->buttons->containedDraw("Back", 800, 480);
}

void TextsSample::controls() {
    if (ui->buttons->onTouch(back, utils->touch->lastClickPoint)) {
        viewsController->setActualView("Welcome");
    }
}
