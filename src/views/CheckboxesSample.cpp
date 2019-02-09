#include "CheckboxesSample.hh"

CheckboxesSample::CheckboxesSample(const std::string &name) : View(name) {

}

void CheckboxesSample::contents() {
    uncheckedZE = ui->checkboxes->drawWithText(10, 40 - 30, one, "Unchecked", utils->PTC->isY(PADTOUCHCTRL_IS_FIRST));
    inderterminateZE = ui->checkboxes->drawWithText(10, 140  - 30, two, "Indeterminate", utils->PTC->isY(2));
    checkedZE = ui->checkboxes->drawWithText(10, 240  - 30, three, "Checked", utils->PTC->isY(3));

    back = ui->buttons->containedDraw("Back", 800, 480, THEME_PRIMARY, utils->PTC->isY(PADTOUCHCTRL_IS_LAST));
}

void CheckboxesSample::controls() {


    if (utils->PTC->isTouchMode()) {
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

        viewsController->setActualView("Welcome");
    }
}

void CheckboxesSample::beforeEnter() {
    one = UNCHECKED;
    two = INDERTERMINATE;
    three = CHECKED;

    this->utils->PTC->setLimit(PADTOUCHCTRL_TYPE_Y, 4);
}
