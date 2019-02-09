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


    if (utils->PTC->isTouchMode()) {
        one = ui->checkboxes->onTouchAuto(uncheckedZE, utils->touch->lastClickPoint);
        two = ui->checkboxes->onTouchAuto(inderterminateZE, utils->touch->lastClickPoint);
        three = ui->checkboxes->onTouchAuto(checkedZE, utils->touch->lastClickPoint);

        four = ui->radioBoxes->onTouchAuto(uncheckedZERB, utils->touch->lastClickPoint);
        five = ui->radioBoxes->onTouchAuto(checkedZERB, utils->touch->lastClickPoint);
    }
    else {
        one = ui->checkboxes->onPadAuto(uncheckedZE, utils->pad->pressed.cross);
        two = ui->checkboxes->onPadAuto(inderterminateZE, utils->pad->pressed.cross);
        three = ui->checkboxes->onPadAuto(checkedZE, utils->pad->pressed.cross);

        four = ui->radioBoxes->onPadAuto(uncheckedZERB, utils->pad->pressed.cross);
        five = ui->radioBoxes->onPadAuto(checkedZERB, utils->pad->pressed.cross);
    }


    if (UiButtons::onTouch(back, utils->touch->lastClickPoint) ||
            UiButtons::onPad(back, utils->pad->pressed.cross) ||
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
