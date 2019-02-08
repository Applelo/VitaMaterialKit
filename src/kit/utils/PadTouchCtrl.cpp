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

        for (auto& limit: yLimits) {
            if (yItem > limit.second) {
                yItem = limit.first;
            }
            if (yItem < limit.first) {
                yItem = limit.second;
            }
        }

        for (auto& limit: xLimits) {
            if (xItem > limit.second) {
                xItem = limit.first;
            }
            if (xItem < limit.first) {
                xItem = limit.second;
            }
        }
    }
}

void PadTouchCtrl::setLimit(PadTouchCtrlType type, int limit) {
    this->clearLimits();
    this->addLimit(type, 1, limit);
    if (type == PADTOUCHCTRL_TYPE_X) {
        xLimit = limit;
    }
    else {
        yLimit = limit;
    }
}

void PadTouchCtrl::setLimit(int xLimit, int yLimit) {
    this->clearLimits();
    this->addLimit(PADTOUCHCTRL_TYPE_X, 1, xLimit);
    this->addLimit(PADTOUCHCTRL_TYPE_Y, 1, yLimit);
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

void PadTouchCtrl::addLimit(PadTouchCtrlType type, int first, int last) {
    //rework add limit to add 4 conditions !
    if (type == PADTOUCHCTRL_TYPE_X) {
        xLimits.emplace(xLimits.begin(), first, last);
    }
    else {
        yLimits.emplace(yLimits.begin(), first, last);
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

