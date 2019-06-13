#include "UtilsScroll.hh"

UtilsScroll::UtilsScroll() {
    this->touch = new UtilsTouch();
}

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


void UtilsScroll::touchController(const std::string& channel) {
    if (touch != nullptr) {
        if(touch->lastTouchPoint.x <= channels[channel].xZone + channels[channel].widthZone
        && touch->lastTouchPoint.x >= channels[channel].xZone
        && touch->lastTouchPoint.y <= channels[channel].yZone + channels[channel].heightZone
        && touch->lastTouchPoint.y >= channels[channel].yZone){

            channels[channel].value -= (channels[channel].scrollDirection == SCROLL_DIR_X) ? touch->scrollDirX : touch->scrollDirY;

        }
    }

    if(channels[channel].value < channels[channel].min) {
        channels[channel].value = channels[channel].min;
    }

    if (channels[channel].value > channels[channel].max) {
        channels[channel].value = channels[channel].max;
    }

}

void UtilsScroll::padController(const std::string& channel, bool decreaseTrigger, bool increaseTrigger, int moveValue, int animationSpeed) {
    if (animationSpeed == 0) {
        animationSpeed = channels[channel].max / moveValue * 4;
    }

    if (decreaseTrigger) {
        channels[channel].animation = -1;
        channels[channel].targetAnimation = channels[channel].value - moveValue;
    }
    if (increaseTrigger) {
        channels[channel].animation = 1;
        channels[channel].targetAnimation = channels[channel].value + moveValue;
    }

    if (channels[channel].animation == -1 && channels[channel].targetAnimation <= channels[channel].value) {
        channels[channel].value -= animationSpeed;
    }

    if (channels[channel].animation == 1 && channels[channel].targetAnimation >= channels[channel].value) {
        channels[channel].value += animationSpeed;
    }

    if(channels[channel].value < channels[channel].min) {
        channels[channel].value = channels[channel].min;
        channels[channel].animation = 0;
    }

    if (channels[channel].value > channels[channel].max) {
        channels[channel].value = channels[channel].max;
        channels[channel].animation = 0;
    }
}

int UtilsScroll::getScroll(std::string channel) {
    return channels[channel].value;
}


