//
// Created by Loïs Boubault on 2019-02-09.
//

#include "CardsSample.hh"

CardsSample::CardsSample(const std::string &name) : View(name) {

}

void CardsSample::contents() {

    ui->cards->initCard(0, 0);
    ui->cards->drawPrimaryTitle("Primary", "Hello i'm secondary");
    ui->cards->drawMedia(nullptr);
    ui->cards->drawSummary("Once Upon a time, a child\ncame into a forest to find\nsomething");
}

void CardsSample::mounted() {

}
