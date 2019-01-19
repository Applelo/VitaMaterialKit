//
// Created by Loïs Boubault on 2019-01-19.
//

#include "ButtonsSample.hh"


ButtonsSample::ButtonsSample(std::string name) : View(name) {

}


void ButtonsSample::contents() {
    ui->buttons->textDraw("Text", 50, 0);
    ui->buttons->textDraw("Text & Icon", 300, 0, ICON_MDI_ACCOUNT);

    ui->buttons->containedDraw("Contained", 50, 150);
    ui->buttons->containedDraw("Contained & Icon", 300, 150, ICON_MDI_ACCOUNT);

    ui->buttons->outlinedDraw("Outlined", 50, 300);
    ui->buttons->outlinedDraw("Outlined & Icon", 300, 300, ICON_MDI_ACCOUNT);

    ui->buttons->floatDraw(ICON_MDI_PLUS, 50, 450);
    ui->buttons->floatDraw(ICON_MDI_PLUS, 300, 450, "Extended Float");
}

void ButtonsSample::controls() {

}
