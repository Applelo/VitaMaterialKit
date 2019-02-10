#include "CardsSample.hh"

CardsSample::CardsSample(const std::string &name) : View(name) {

}

void CardsSample::contents() {

    for (int i = 0; i < 8; ++i) {
        ui->cards->initCard(10 + (10 * i) + (i * 400) - utils->scroll->getScroll("cards"), 10);
        ui->cards->drawPrimaryTitle("Primary oiejzfoizfj oiejzfoeijf fozeijfoizejf", "Hello i'm secondary");
        ui->cards->drawMedia(nullptr);
        ui->cards->drawSummary("Once Upon a time, a child came into a forest to find something", 100);
    }

}

void CardsSample::controls() {
    utils->scroll->controller("cards", utils->pad->pressed.left, utils->pad->pressed.right, 400);
}

void CardsSample::mounted() {
    utils->scroll->create("cards", SCROLL_DIR_X, 0, 400 * 6, 10, 10, 960, 400);
}
