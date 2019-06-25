#include "ButtonsSample.hh"


ButtonsSample::ButtonsSample(const std::string &name) : View(name) {

}


void ButtonsSample::contents() {
    ui->buttons->textDraw("Text", 50, 0, THEME_PRIMARY, this->utils->PTC->isXY(PADTOUCHCTRL_IS_FIRST, PADTOUCHCTRL_IS_FIRST));
    ui->buttons->textDraw("Text & Icon", 300, 0, THEME_PRIMARY, this->utils->PTC->isXY(2, PADTOUCHCTRL_IS_FIRST), ICON_MDI_ACCOUNT);

    ui->buttons->containedDraw("Contained", 50, 150, THEME_PRIMARY, this->utils->PTC->isXY(PADTOUCHCTRL_IS_FIRST, 2));
    ui->buttons->containedDraw("Contained & Icon", 300, 150, THEME_PRIMARY, this->utils->PTC->isXY(2, 2), ICON_MDI_ACCOUNT);

    ui->buttons->outlinedDraw("Outlined", 50, 300, THEME_PRIMARY, this->utils->PTC->isXY(PADTOUCHCTRL_IS_FIRST, 3));
    ui->buttons->outlinedDraw("Outlined & Icon", 300, 300, THEME_PRIMARY, this->utils->PTC->isXY(2, 3), ICON_MDI_ACCOUNT);

    ui->buttons->floatDraw(ICON_MDI_PLUS, 50, 450, THEME_PRIMARY, this->utils->PTC->isXY(PADTOUCHCTRL_IS_FIRST, PADTOUCHCTRL_IS_LAST));
    ui->buttons->floatDraw(ICON_MDI_PLUS, 300, 450, THEME_PRIMARY, this->utils->PTC->isXY(2, PADTOUCHCTRL_IS_LAST), "Extended Float");

    back = ui->buttons->containedDraw("Back", 800, 480, THEME_PRIMARY, this->utils->PTC->isXY(PADTOUCHCTRL_IS_LAST, PADTOUCHCTRL_IS_LAST));
}

void ButtonsSample::controls() {
    if (EventUi::onTouch(back, utils->touch->lastClickPoint)||
            EventUi::onPad(back, utils->pad->pressed.cross) ||
    utils->pad->pressed.circle
    ) {
        viewsController->setActualView("Welcome");
    }
}

void ButtonsSample::beforeEnter() {
    this->utils->PTC->setLimit(3, 4);
    this->utils->PTC->addLimit(PADTOUCHCTRL_TYPE_X, 1, 1, 2);
    this->utils->PTC->addLimit(PADTOUCHCTRL_TYPE_X, 2, 1, 2);
    this->utils->PTC->addLimit(PADTOUCHCTRL_TYPE_X, 3, 1, 2);
}
