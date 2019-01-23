//
// Created by Loïs Boubault on 2019-01-22.
//

#include "CheckboxesSample.hh"

CheckboxesSample::CheckboxesSample(const std::string &name) : View(name) {

}

void CheckboxesSample::contents() {
    ui->texts->draw(100, 40, Body1, "Unchecked");
    ui->texts->draw(100, 140, Body1, "Indeterminate");
    ui->texts->draw(100, 240, Body1, "Checked");

    uncheckedZE = ui->checkboxes->draw(10, 40 - 30, one, selector == 1);
    inderterminateZE = ui->checkboxes->draw(10, 140  - 30, two, selector == 2);
    checkedZE = ui->checkboxes->draw(10, 240  - 30, three, selector == 3);

    back = ui->buttons->containedDraw("Back", 800, 480, selector == NUMBER_OF_BUTTONS_CHECKBOXES);
}

void CheckboxesSample::controls() {

    //pad
    if (utils->pad->pressed.down) {
        selector++;
    }
    if (utils->pad->pressed.up) {
        selector--;
    }
    if (selector > NUMBER_OF_BUTTONS_CHECKBOXES)
        selector = 1;
    if (selector == 0)
        selector = NUMBER_OF_BUTTONS_CHECKBOXES;

    //touch & pad switch
    if (utils->touch->clicking) {
        selector = -1;
    }
    if (utils->pad->held.clicking && selector == -1) {
        selector = 1;
    }

    if (selector == -1) {
        one = ui->checkboxes->onTouchAuto(uncheckedZE, utils->touch->lastClickPoint);
        two = ui->checkboxes->onTouchAuto(inderterminateZE, utils->touch->lastClickPoint);
        three = ui->checkboxes->onTouchAuto(checkedZE, utils->touch->lastClickPoint);
    }
    else {
        one = ui->checkboxes->onPadAuto(uncheckedZE, utils->pad->pressed.cross);
        two = ui->checkboxes->onPadAuto(inderterminateZE, utils->pad->pressed.cross);
        three = ui->checkboxes->onPadAuto(checkedZE, utils->pad->pressed.cross);
    }



    if (ui->buttons->onTouch(back, utils->touch->lastClickPoint) ||
        ui->buttons->onPad(back, utils->pad->pressed.cross) ||
        utils->pad->pressed.circle) {

        one = UNCHECKED;
        two = INDERTERMINATE;
        three = CHECKED;

        viewsController->setActualView("Welcome");
    }
}