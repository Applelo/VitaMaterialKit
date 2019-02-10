#include <utility>

#include "UiCards.hh"

UiCards::UiCards(UiTheme *theme, UiTexts *texts, UiIcons *icons, UiButtons *buttons) : theme(theme), texts(texts),
                                                                                       icons(icons), buttons(buttons) {}


void UiCards::resetCard() {
    x = 0;
    y = 0;
    width = 0;
    height = 0;
}

void UiCards::resetOffset() {
    xOffset = 0;
    yOffset = 0;
    heightOffset = 0;
}

ZoneEvent UiCards::initCard(int x, int y, int width, TypeTheme typeTheme) {

    //draw container
    zoneEvent.x = x;
    zoneEvent.y = y;
    zoneEvent.width = width;
    zoneEvent.height = height;

    vita2d_draw_rectangle(x, y, width, height, CARDS_DEFAULT_COLOR_BACKGROUND);

    //reset &  start to draw new card
    this->resetCard();
    this->x = x;
    this->y = y;
    this->width = width;
    this->typeTheme = typeTheme;

    return zoneEvent;
}


ZoneEvent UiCards::drawPrimaryTitle(std::string headerText, std::string subHead, int height) {
    this->resetOffset();

    zoneEvent.x = x;
    zoneEvent.y = y;
    zoneEvent.width = width;

    heightOffset = CARDS_DEFAULT_PADDING;
    xOffset = x + CARDS_DEFAULT_PADDING;
    yOffset = y + CARDS_DEFAULT_PADDING;

    headerText = texts->applyTextWidthLimit(headerText, width - (CARDS_DEFAULT_PADDING * 2), texts->getTextStyleData(H6));
    if (height > 0) {
        headerText = texts->applyTextHeightLimit(headerText, (height / 2) - CARDS_DEFAULT_PADDING, texts->getTextStyleData(H6));
        headerText.replace(headerText.length() - 4, 3, "...");
    }
    texts->draw(xOffset, yOffset, H6, CARDS_DEFAULT_COLOR_HEADER_TEXT, headerText);
    textData = texts->getTextData(headerText, H6);
    heightOffset += textData.height;

    subHead = texts->applyTextWidthLimit(subHead, width - (CARDS_DEFAULT_PADDING * 2), texts->getTextStyleData(Body1));
    if (height > 0) {
        subHead = texts->applyTextHeightLimit(subHead, (height / 2) - (CARDS_DEFAULT_PADDING * 2), texts->getTextStyleData(Body1));
        subHead.replace(subHead.length() - 4, 3, "...");
    }
    texts->draw(xOffset, yOffset + textData.height + 4, Body1, CARDS_DEFAULT_COLOR_SUBHEAD_TEXT, subHead);
    textData = texts->getTextData(subHead, Body1);
    heightOffset += textData.height + 4;

    heightOffset += CARDS_DEFAULT_PADDING;

    zoneEvent.height = heightOffset;
    this->height = heightOffset;

    y += heightOffset;

    return zoneEvent;
}

ZoneEvent UiCards::drawMedia(vita2d_texture *media, int height) {
    this->resetOffset();

    if (media == nullptr) {
        heightOffset = 250;
        vita2d_draw_rectangle(x, y, width, height == 0 ? heightOffset : height, CARDS_DEFAULT_COLOR_HEADER_TEXT);
    }
    else {
        heightOffset = vita2d_texture_get_height(media);
        vita2d_draw_texture_part(media, x, y, 0, 0, width, height == 0 ? heightOffset : height);
    }


    zoneEvent.x = x;
    zoneEvent.y = y;
    zoneEvent.width = width;
    zoneEvent.height = heightOffset;

    y += heightOffset;
    this->height +=heightOffset;

    return zoneEvent;
}

ZoneEvent UiCards::drawSummary(std::string text, int height) {
    this->resetOffset();

    text = texts->applyTextWidthLimit(text, width - (CARDS_DEFAULT_PADDING * 2), texts->getTextStyleData(Body1));
    if (height > 0) {
        text = texts->applyTextHeightLimit(text, height - (CARDS_DEFAULT_PADDING * 2), texts->getTextStyleData(Body1), TEXT_LIMIT_START);
        text.replace(text.length() - 4, 3, "...");
    }

    texts->draw(x + CARDS_DEFAULT_PADDING, y + CARDS_DEFAULT_PADDING, Body1, CARDS_DEFAULT_COLOR_SUBHEAD_TEXT, text);
    textData = texts->getTextData(text, Body1);

    heightOffset = textData.height + CARDS_DEFAULT_PADDING + CARDS_DEFAULT_PADDING;

    zoneEvent.x = x;
    zoneEvent.y = y;
    zoneEvent.width = width;
    zoneEvent.height = heightOffset;

    this->height += heightOffset;

    return zoneEvent;
}

