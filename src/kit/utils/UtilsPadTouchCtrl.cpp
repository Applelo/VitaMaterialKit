#include "UtilsPadTouchCtrl.hh"

UtilsPadTouchCtrl::UtilsPadTouchCtrl(UtilsPad *pad) {
    touchMode = false;
    ctrlMode = true;
    mode = PADTOUCHCTRL_MODE_CTRL;
}

UtilsPadTouchCtrl::UtilsPadTouchCtrl(UtilsPad *pad, UtilsTouch *touch) : pad(pad), touch(touch) {
    this->setMode();
}

UtilsPadTouchCtrl::UtilsPadTouchCtrl(UtilsPad *pad, UtilsTouch *touch, UtilsScroll *scroll) : pad(pad), touch(touch), scroll(scroll) {
    this->setMode();
}

void UtilsPadTouchCtrl::setMode() {
    model = sceKernelGetModel();
    mode = PADTOUCHCTRL_MODE_AUTO;

    if (model == SCE_KERNEL_MODEL_VITATV) {
        touchMode = false;
        ctrlMode = true;
    }
    else {
        touchMode = true;
        ctrlMode = false;
    }
}

void UtilsPadTouchCtrl::controller() {

    if (this->touch != nullptr) {
        if (this->touch->clicking && ctrlMode && mode == PADTOUCHCTRL_MODE_AUTO) {
            yOldItem = yItem;
            xOldItem = xItem;

            yItem = -1;
            xItem = -1;

            touchMode = true;
            ctrlMode = false;
        }
    }

    if (this->pad->held.clicking && touchMode && mode == PADTOUCHCTRL_MODE_AUTO) {
        touchMode = false;
        ctrlMode = true;

        yItem = yOldItem;
        xItem = xOldItem;
    }

    if (ctrlMode) {
        //add support for analog stick
        if (pad->pressed.down) {
           yItem++;
        }
        if (pad->pressed.up) {
           yItem--;
        }
        if (pad->pressed.right) {
            xItem++;
        }
        if (pad->pressed.left) {
            xItem--;
        }

        if (yItem > yGlobalLimit) {
            yItem = 1;
        }
        if (yItem < 1) {
            yItem = yGlobalLimit;
        }

        if (xItem > xGlobalLimit) {
            xItem = 1;
        }
        if (xItem < 1) {
            xItem = xGlobalLimit;
        }

        for (auto& limit: yLimits) {

            if (xItem == limit.first) {
                if (yItem > limit.second.second) {
                    yItem = limit.second.second;
                }
                if (yItem < limit.second.first) {
                    yItem = limit.second.first;
                }
            }
        }

        for (auto& limit: xLimits) {

            if (yItem == limit.first) {
                if (xItem > limit.second.second) {
                    xItem = limit.second.second;
                }
                if (xItem < limit.second.first) {
                    xItem = limit.second.first;
                }
            }
        }
    }
}



void UtilsPadTouchCtrl::setLimit(PadTouchCtrlType type, int limit) {
    this->clearLimits();
    this->updateLimit(type, limit);
}

void UtilsPadTouchCtrl::setLimit(PadTouchCtrlType type, int limit, int start) {
    this->setLimit(type, limit);
    this->updateStart(type, start);
}

void UtilsPadTouchCtrl::setLimit(int xLimit, int yLimit) {
    this->clearLimits();
    this->updateLimit(xLimit, yLimit);
}

void UtilsPadTouchCtrl::setLimit(int xLimit, int yLimit, int xStart, int yStart) {
    this->setLimit(xLimit, yLimit);
    this->updateStart(xStart, yStart);
}


void UtilsPadTouchCtrl::updateLimit(PadTouchCtrlType type, int limit) {
    if (type == PADTOUCHCTRL_TYPE_X) {
        xGlobalLimit = limit;
    }
    else {
        yGlobalLimit = limit;
    }
}

void UtilsPadTouchCtrl::updateStart(PadTouchCtrlType type, int start) {
    if (type == PADTOUCHCTRL_TYPE_X) {
        xOldItem = start;
        if (ctrlMode) {
            xItem = start;
        }
    }
    else {
        yOldItem = start;
        if (ctrlMode) {
            yItem = start;
        }
    }
}

void UtilsPadTouchCtrl::updateLimit(int xLimit, int yLimit) {
    this->xGlobalLimit = xLimit;
    this->yGlobalLimit = yLimit;
}

void UtilsPadTouchCtrl::updateStart(int xStart, int yStart) {
    xItem = xStart;
    yItem = yStart;
    if (ctrlMode) {
        xItem = xStart;
        yItem = yStart;
    }
}

bool UtilsPadTouchCtrl::isX(int x) {
    return xItem == x;
}

bool UtilsPadTouchCtrl::isY(int y) {
    return yItem == y;
}

bool UtilsPadTouchCtrl::isXY(int x, int y) {
    return isX(x) && isY(y);
}

bool UtilsPadTouchCtrl::isX(PadTouchCtrlIs x) {
    if (x == PADTOUCHCTRL_IS_FIRST) {
        return xItem == 1;
    }
    return xItem == xGlobalLimit;
}

bool UtilsPadTouchCtrl::isY(PadTouchCtrlIs y) {
    if (y == PADTOUCHCTRL_IS_FIRST) {
        return yItem == 1;
    }
    return yItem == yGlobalLimit;
}

bool UtilsPadTouchCtrl::isXY(PadTouchCtrlIs x, PadTouchCtrlIs y) {
    return isX(x) && isY(y);
}

bool UtilsPadTouchCtrl::isXY(int x, PadTouchCtrlIs y) {
    return isX(x) && isY(y);
}

bool UtilsPadTouchCtrl::isXY(PadTouchCtrlIs x, int y) {
    return isX(x) && isY(y);
}

void UtilsPadTouchCtrl::addLimit(PadTouchCtrlType type, int line, int first, int last) {
    //rework add limit to add 4 conditions !
    if (type == PADTOUCHCTRL_TYPE_X) {
        xLimits.emplace(xLimits.begin(), line, std::make_pair(first, last));
    }
    else {
        yLimits.emplace(yLimits.begin(), line, std::make_pair(first, last));
    }
}

void UtilsPadTouchCtrl::clearLimits() {
    xLimits.clear();
    yLimits.clear();
}

std::string UtilsPadTouchCtrl::debug() {
    debugText = "x,y=";
    debugText += std::to_string(xItem) + "," + std::to_string(yItem);

    debugText = "x,y old=";
    debugText += std::to_string(xOldItem) + "," + std::to_string(yOldItem);

    debugText += "\nGlobalLimit x,y=";
    debugText += std::to_string(xGlobalLimit) + "," + std::to_string(yGlobalLimit);

    debugText += "\nxLimits: ";
    for (auto& limit: xLimits) {
        debugText += std::to_string(limit.first) + "=";
        debugText += std::to_string(limit.second.first) + "," + std::to_string(limit.second.second) + "|";
    }

    debugText += "\nyLimits: ";
    for (auto& limit: yLimits) {
        debugText += std::to_string(limit.first) + "=";
        debugText += std::to_string(limit.second.first) + "," + std::to_string(limit.second.second) + "|";
    }

    debugText += "\nMode: ";
    debugText += this->isCtrlMode() ? "ctrl" : "touch";
    debugText += this->getMode() == PADTOUCHCTRL_MODE_AUTO ? "|auto" : this->getMode() == PADTOUCHCTRL_MODE_CTRL ? "|ctrl" : "|touch";


    return  debugText;
}

bool UtilsPadTouchCtrl::isTouchMode() const {
    return touchMode;
}

bool UtilsPadTouchCtrl::isCtrlMode() const {
    return ctrlMode;
}

PadTouchCtrlMode UtilsPadTouchCtrl::getMode() {
    return mode;
}

void UtilsPadTouchCtrl::updateMode(PadTouchCtrlMode mode) {
    this->mode = mode;

    if (this->mode == PADTOUCHCTRL_MODE_CTRL) {
        ctrlMode = true;
        touchMode = false;
    }
    else if (this->mode == PADTOUCHCTRL_MODE_TOUCH) {
        touchMode = true;
        ctrlMode = false;
    }
}

void UtilsPadTouchCtrl::scrollController(const std::string& channel, int line, int size) {

    if (ctrlMode) {

        if (scroll->getScrollDirection(channel) == SCROLL_DIR_X && line == yItem) {
            scrollBuffers[channel] = size * (xItem - 1);
        }

        if (scroll->getScrollDirection(channel) == SCROLL_DIR_Y && line == xItem) {
            scrollBuffers[channel] = size * (yItem - 1);
        }

    }


    scrollBuffers[channel] = scroll->controller(channel, ctrlMode, scrollBuffers[channel]);
}

