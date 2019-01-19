#include "ButtonsSample.hh"


ButtonsSample::ButtonsSample(std::string name) : View(name) {

}


void ButtonsSample::contents() {
    ui->buttons->textDraw("Text", 50, 0);
    ui->buttons->textDraw("Text & Icon", 300, 0, false, ICON_MDI_ACCOUNT);

    ui->buttons->containedDraw("Contained", 50, 150);
    ui->buttons->containedDraw("Contained & Icon", 300, 150, false, ICON_MDI_ACCOUNT);

    ui->buttons->outlinedDraw("Outlined", 50, 300);
    ui->buttons->outlinedDraw("Outlined & Icon", 300, 300, false, ICON_MDI_ACCOUNT);

    ui->buttons->floatDraw(ICON_MDI_PLUS, 50, 450);
    ui->buttons->floatDraw(ICON_MDI_PLUS, 300, 450, false, "Extended Float");

    back = ui->buttons->containedDraw("Back", 800, 480);
}

void ButtonsSample::controls() {
    if (ui->buttons->onTouch(back, utils->touch->lastClickPoint)) {
        viewsController->setActualView("Welcome");
    }
}
