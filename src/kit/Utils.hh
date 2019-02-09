#ifndef VITAMATERIALKIT_UTILS_HH
#define VITAMATERIALKIT_UTILS_HH


#include "utils/UtilsI18n.hpp"
#include "utils/UtilsTouch.hpp"
#include "utils/UtilsPad.hpp"
#include "utils/UtilsPadTouchCtrl.hh"

class Utils {
protected:
    virtual void init();
public:
    UtilsTouch *touch;
    UtilsPad *pad;
    UtilsI18n *i18n;
    UtilsPadTouchCtrl *PTC;
    Utils();
    virtual void read();
};


#endif //VITAMATERIALKIT_UTILS_HH
