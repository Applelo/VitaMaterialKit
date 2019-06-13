#include "CardsSample.hh"

CardsSample::CardsSample(const std::string &name) : View(name) {

}

void CardsSample::contents() {

    for (int i = 0; i < 10; ++i) {
        ui->cards->start(10 + (10 * i) + (i * 400) - utils->scroll->getScroll("cards"), 10, CARDS_DEFAULT_WIDTH, THEME_PRIMARY,  cardsSelector == i + 1);
        ui->cards->drawPrimaryTitle(cardPrePrimaryTitle);
        ui->cards->drawMedia(nullptr);
        ui->cards->drawSummary(cardPreSummary);
        ui->cards->end();
        ui->texts->draw(10 + (10 * i) + (i * 400) - utils->scroll->getScroll("cards"), 10, Body1, std::to_string(i));
    }

    back = ui->buttons->containedDraw("Back", 800, 480);
}

void CardsSample::controls() {
    if (ui->buttons->onTouch(back, utils->touch->lastClickPoint)||
        ui->buttons->onPad(back, utils->pad->pressed.cross) ||
        utils->pad->pressed.circle
            ) {
        viewsController->setActualView("Welcome");
    }

    if (utils->pad->pressed.left) {
        cardsSelector--;
    }
    if (utils->pad->pressed.right) {
        cardsSelector++;
    }

    utils->scroll->touchController("cards");
    utils->scroll->padController("cards", utils->pad->pressed.left, utils->pad->pressed.right, 400);
}

void CardsSample::mounted() {
    cardPrePrimaryTitle = ui->cards->prePrimaryTitle("Lorem ipsum dolor sit amet.", "Applelo", CARDS_DEFAULT_WIDTH);
    cardPreSummary = ui->cards->preSummaryTitle("Maecenas et luctus augue, non volutpat orci. Vestibulum ultrices rutrum metus, ut malesuada velit malesuada sit amet.", CARDS_DEFAULT_WIDTH, 100);
    utils->scroll->create("cards", SCROLL_DIR_X, 0, CARDS_DEFAULT_WIDTH * 8, 10, 10, 960, 400);
    cardsSelector = 1;
}
