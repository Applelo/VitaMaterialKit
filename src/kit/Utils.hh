#ifndef VITAMATERIALKIT_UTILS_HH
#define VITAMATERIALKIT_UTILS_HH

#include "utils/UtilsI18n.hh"
#include "utils/UtilsTouch.hh"
#include "utils/UtilsPad.hh"
#include "utils/UtilsPadTouchCtrl.hh"
#include "utils/UtilsScroll.hh"

class Utils {
protected:
    virtual void init();
public:
    UtilsTouch *touch;
    UtilsPad *pad;
    UtilsI18n *i18n;
    UtilsPadTouchCtrl *PTC;
    UtilsScroll *scroll;

    Utils();
    virtual void read();
};


#endif //VITAMATERIALKIT_UTILS_HH
