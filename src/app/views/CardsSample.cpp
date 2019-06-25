#include "CardsSample.hh"


CardsSample::CardsSample(const std::string &name) : View(name) {

}

void CardsSample::contents() {

    for (int i = 0; i < 10; ++i) {
        ui->cards->start(10 + (10 * i) + (i * 400) - utils->scroll->getValue("cards"), 10, CARDS_DEFAULT_WIDTH, THEME_PRIMARY,  this->utils->PTC->isXY(i + 1, PADTOUCHCTRL_IS_FIRST));
        ui->cards->drawPrimaryTitle(cardPrePrimaryTitle);
        ui->cards->drawMedia(nullptr);
        ui->cards->drawSummary(cardPreSummary);
        ui->cards->end();
        ui->texts->draw(10 + (10 * i) + (i * 400) - utils->scroll->getValue("cards"), 10, Body1, std::to_string(i));
    }
    ui->texts->draw(10, 480, Body1, std::to_string(utils->scroll->getValue("cards")));

    back = ui->buttons->containedDraw("Back", 800, 480, THEME_PRIMARY, this->utils->PTC->isY(PADTOUCHCTRL_IS_LAST));
}

void CardsSample::controls() {
    if (EventUi::onTouch(back, utils->touch->lastClickPoint)||
            EventUi::onPad(back, utils->pad->pressed.cross) ||
        utils->pad->pressed.circle
            ) {
        viewsController->setActualView("Welcome");
    }

    utils->PTC->scrollController("cards", 1, 410);
}

void CardsSample::mounted() {
    cardPrePrimaryTitle = ui->cards->prePrimaryTitle("Lorem ipsum dolor sit amet.", "Applelo");
    cardPreSummary = ui->cards->preSummaryTitle("Maecenas et luctus augue, non volutpat orci. Vestibulum ultrices rutrum metus, ut malesuada velit malesuada sit amet.", CARDS_DEFAULT_WIDTH, 100);
    utils->scroll->create("cards", SCROLL_DIR_X, 0, CARDS_DEFAULT_WIDTH * 8, 10, 10, SCREEN_WIDTH, CARDS_DEFAULT_WIDTH);

}

void CardsSample::beforeEnter() {
    this->utils->PTC->setLimit(10, 2);
    this->utils->PTC->addLimit(PADTOUCHCTRL_TYPE_X, 2, 1, 1);
}
