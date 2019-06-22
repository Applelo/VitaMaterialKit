#include "UtilsScroll.hh"

UtilsScroll::UtilsScroll() {}

UtilsScroll::UtilsScroll(UtilsTouch *touch) : touch(touch) {}


void UtilsScroll::create(const std::string& channel, ScrollDirection scrollDirection, int min, int max, int xZone, int yZone, int widthZone, int heightZone) {
    ScrollChannelData scrollChannelData;

    scrollChannelData.scrollDirection = scrollDirection;
    scrollChannelData.max = max;
    scrollChannelData.min = min;
    scrollChannelData.value = 0;

    scrollChannelData.xZone = xZone;
    scrollChannelData.yZone = yZone;
    scrollChannelData.widthZone = widthZone;
    scrollChannelData.heightZone = heightZone;

    channels[channel] = scrollChannelData;
}

void UtilsScroll::remove(const std::string& channel) {
    channels.erase(channel);
}

ScrollChannelData UtilsScroll::getChannelData(const std::string& channel) {
    return channels[channel];
}

int UtilsScroll::controller(const std::string &channel, bool isCtrl, int value) {

    if (isCtrl) {
        channels[channel].value = value;
    }
    else {
        if (touch != nullptr) {
            if (touch->lastTouchPoint.x <= channels[channel].xZone + channels[channel].widthZone
                && touch->lastTouchPoint.x >= channels[channel].xZone
                && touch->lastTouchPoint.y <= channels[channel].yZone + channels[channel].heightZone
                && touch->lastTouchPoint.y >= channels[channel].yZone) {

                channels[channel].value -= (channels[channel].scrollDirection == SCROLL_DIR_X) ? touch->scrollDirX
                                                                                               : touch->scrollDirY;

            }
        }
    }

    if(channels[channel].value < channels[channel].min) {
        channels[channel].value = channels[channel].min;
    }

    if (channels[channel].value > channels[channel].max) {
        channels[channel].value = channels[channel].max;
    }

    return channels[channel].value;
}


