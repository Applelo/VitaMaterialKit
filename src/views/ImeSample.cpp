#include "ImeSample.hh"

ImeSample::ImeSample(const std::string &name) : View(name) {
    ime = new IME();
}

void ImeSample::contents() {

    ui->texts->draw(10, 10, Body1, result);

    keyboard = ui->buttons->containedDraw("Set text", 450, 250);

    back = ui->buttons->containedDraw("Back", 800, 480);
}

void ImeSample::controls() {
    if (ui->buttons->onTouch(keyboard, utils->touch->lastClickPoint)) {
       result = ime->getUserText("Text", result.c_str());
    }

    if (ui->buttons->onTouch(back, utils->touch->lastClickPoint)) {
        viewsController->setActualView("Welcome");
    }
}
