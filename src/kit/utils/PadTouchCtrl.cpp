#include "PadTouchCtrl.hh"

PadTouchCtrl::PadTouchCtrl(Pad *pad) {
    touchMode = false;
    ctrlMode = true;
}


PadTouchCtrl::PadTouchCtrl(Pad *pad, Touch *touch) : pad(pad), touch(touch) {
    model = sceKernelGetModel();

    if (model == SCE_KERNEL_MODEL_VITATV) {
        touchMode = false;
        ctrlMode = true;
    }
    else {
        touchMode = true;
        ctrlMode = false;
    }
}

void PadTouchCtrl::controller() {

    if (this->touch != nullptr) {
        if (this->touch->clicking && ctrlMode) {
            yOldItem = yItem;
            xOldItem = xItem;

            yItem = -1;
            xItem = -1;

            touchMode = true;
            ctrlMode = false;
        }
    }

    if (this->pad->held.clicking && touchMode) {
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

        if (yItem > yLimit) {
            yItem = 1;
        }
        if (yItem < 1) {
            yItem = yLimit;
        }

        if (xItem > xLimit) {
            xItem = 1;
        }
        if (xItem < 1) {
            xItem = xLimit;
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



void PadTouchCtrl::setLimit(PadTouchCtrlType type, int limit) {
    this->clearLimits();
    if (type == PADTOUCHCTRL_TYPE_X) {
        xLimit = limit;
    }
    else {
        yLimit = limit;
    }
}

void PadTouchCtrl::setLimit(int xLimit, int yLimit) {
    this->clearLimits();
    this->xLimit = xLimit;
    this->yLimit = yLimit;
}

bool PadTouchCtrl::isX(int x) {
    return xItem == x;
}

bool PadTouchCtrl::isY(int y) {
    return yItem == y;
}

bool PadTouchCtrl::isXY(int x, int y) {
    return isX(x) && isY(y);
}

bool PadTouchCtrl::isX(PadTouchCtrlIs x) {
    if (x == PADTOUCHCTRL_IS_FIRST) {
        return xItem == 1;
    }
    return xItem == xLimit;
}

bool PadTouchCtrl::isY(PadTouchCtrlIs y) {
    if (y == PADTOUCHCTRL_IS_FIRST) {
        return yItem == 1;
    }
    return yItem == yLimit;
}

bool PadTouchCtrl::isXY(PadTouchCtrlIs x, PadTouchCtrlIs y) {
    return isX(x) && isY(y);
}

bool PadTouchCtrl::isXY(int x, PadTouchCtrlIs y) {
    return isX(x) && isY(y);
}

bool PadTouchCtrl::isXY(PadTouchCtrlIs x, int y) {
    return isX(x) && isY(y);
}

void PadTouchCtrl::addLimit(PadTouchCtrlType type, int line, int first, int last) {
    //rework add limit to add 4 conditions !
    if (type == PADTOUCHCTRL_TYPE_X) {
        xLimits.emplace(xLimits.begin(), line, std::make_pair(first, last));
    }
    else {
        yLimits.emplace(yLimits.begin(), line, std::make_pair(first, last));
    }
}


bool PadTouchCtrl::isTouchMode() const {
    return touchMode;
}

bool PadTouchCtrl::isCtrlMode() const {
    return ctrlMode;
}

void PadTouchCtrl::clearLimits() {
    xLimits.clear();
    yLimits.clear();
}

