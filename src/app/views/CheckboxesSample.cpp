#include "CheckboxesSample.hh"

CheckboxesSample::CheckboxesSample(const std::string &name) : View(name) {

}

void CheckboxesSample::contents() {
    uncheckedZE = ui->checkboxes->drawWithText(10, 10, one, "Unchecked", utils->PTC->isY(PADTOUCHCTRL_IS_FIRST));
    inderterminateZE = ui->checkboxes->drawWithText(10, 100, two, "Indeterminate", utils->PTC->isY(2));
    checkedZE = ui->checkboxes->drawWithText(10, 200, three, "Checked", utils->PTC->isY(3));

    uncheckedZERB = ui->radioBoxes->drawWithText(10, 300, four, "Unchecked", utils->PTC->isY(4));
    checkedZERB = ui->radioBoxes->drawWithText(10, 400, five, "Checked", utils->PTC->isY(5));

    back = ui->buttons->containedDraw("Back", 800, 480, THEME_PRIMARY, utils->PTC->isY(PADTOUCHCTRL_IS_LAST));
}

void CheckboxesSample::controls() {

    one = ui->checkboxes->onAuto(uncheckedZE, utils->touch->lastClickPoint, utils->pad->pressed.cross, utils->PTC->isTouchMode());
    two = ui->checkboxes->onAuto(inderterminateZE, utils->touch->lastClickPoint, utils->pad->pressed.cross, utils->PTC->isTouchMode());
    three = ui->checkboxes->onAuto(checkedZE, utils->touch->lastClickPoint, utils->pad->pressed.cross, utils->PTC->isTouchMode());
    four = ui->radioBoxes->onAuto(uncheckedZERB, utils->touch->lastClickPoint, utils->pad->pressed.cross, utils->PTC->isTouchMode());
    five = ui->radioBoxes->onAuto(checkedZERB, utils->touch->lastClickPoint, utils->pad->pressed.cross, utils->PTC->isTouchMode());

    if (EventUi::on(back, utils->touch->lastClickPoint, utils->pad->pressed.cross, utils->PTC->isTouchMode()) ||
        utils->pad->pressed.circle) {

        viewsController->setActualView("Welcome");
    }
}

void CheckboxesSample::beforeEnter() {
    one = CHECKBOX_UNCHECKED;
    two = CHECKBOX_INDERTERMINATE;
    three = CHECKBOX_CHECKED;

    four = RADIOBOX_UNCHECKED;
    five = RADIOBOX_CHECKED;

    this->utils->PTC->setLimit(PADTOUCHCTRL_TYPE_Y, 6);
}
