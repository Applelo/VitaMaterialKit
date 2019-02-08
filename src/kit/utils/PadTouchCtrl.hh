#ifndef VITAMATERIALKIT_PADTOUCHCTRL_HH
#define VITAMATERIALKIT_PADTOUCHCTRL_HH

#include <psp2/kernel/sysmem.h>
#include <list>

#include "Pad.hpp"
#include "Touch.hpp"

typedef enum PadTouchCtrlType {
    PADTOUCHCTRL_TYPE_X,
    PADTOUCHCTRL_TYPE_Y
} PadTouchCtrlType;

typedef enum PadTouchCtrlIs {
    PADTOUCHCTRL_IS_FIRST,
    PADTOUCHCTRL_IS_LAST
} PadTouchCtrlIs;

class PadTouchCtrl {
private:
    Pad *pad;
    Touch *touch;
    int model;
    int xItem, yItem, xLimit, yLimit;
    int xOldItem, yOldItem;
    bool touchMode, ctrlMode;

    std::list <std::pair<int, int> > xLimits, yLimits;
    void clearLimits();
public:

    PadTouchCtrl(Pad *pad);
    PadTouchCtrl(Pad *pad, Touch *touch);

    void controller();
    void setLimit(PadTouchCtrlType type, int limit);
    void setLimit(int xLimit, int yLimit);

    void addLimit(PadTouchCtrlType type, int first, int last);


    bool isX(int x);
    bool isX(PadTouchCtrlIs x);
    bool isY(int y);
    bool isY(PadTouchCtrlIs y);

    bool isXY(int x, int y);
    bool isXY(PadTouchCtrlIs x, PadTouchCtrlIs y);
    bool isXY(int x, PadTouchCtrlIs y);
    bool isXY(PadTouchCtrlIs x, int y);


    bool isTouchMode() const;
    bool isCtrlMode() const;
};


#endif //VITAMATERIALKIT_PADTOUCHCTRL_HH