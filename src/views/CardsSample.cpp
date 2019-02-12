#include "CardsSample.hh"

CardsSample::CardsSample(const std::string &name) : View(name) {

}

void CardsSample::contents() {

    for (int i = 0; i < 6; ++i) {
        ui->cards->initCard(10 + (10 * i) + (i * 400) - utils->scroll->getScroll("cards"), 10, 200);
        ui->cards->drawPrimaryTitle(cardPrePrimaryTitle);
        //ui->cards->drawMedia(nullptr);
       ui->cards->drawSummary(cardPreSummary);
    }

}

void CardsSample::controls() {
    utils->scroll->controller("cards", utils->pad->pressed.left, utils->pad->pressed.right, 400);
}

void CardsSample::mounted() {
    cardPrePrimaryTitle = ui->cards->prePrimaryTitle("[Vita] Vita Homebrew Browser Wiki : une solution alternative pour télécharger les applications bannies de VitaDB (ONElua notamment)", "test", 200, 200);
    cardPreSummary = ui->cards->preSummaryTitle("Once Upon a time, a child came into a forest to find something", 200, 100);
    utils->scroll->create("cards", SCROLL_DIR_X, 0, 400 * 6, 10, 10, 960, 400);
}
